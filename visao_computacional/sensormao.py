import cv2
import mediapipe as mp
import pyautogui
import time
import math

pyautogui.FAILSAFE = False

TEMPO_PARADO = 4.0
LIMITE_MOVIMENTO = 30

mp_hands = mp.solutions.hands
mp_draw = mp.solutions.drawing_utils

hands = mp_hands.Hands(
    max_num_hands=1,
    min_detection_confidence=0.7,
    min_tracking_confidence=0.7
)

screen_w, screen_h = pyautogui.size()

cap = cv2.VideoCapture(0, cv2.CAP_DSHOW)

if not cap.isOpened():
    print("Erro: camera nao abriu.")
    exit()

last_x, last_y = None, None
still_start = None
clicked = False

print("Sensor de mao iniciado.")
print("Mostre a mao para a camera.")
print("Fique parado por 4 segundos para clicar.")
print("Pressione ESC para sair.")

while True:
    ret, frame = cap.read()

    if not ret:
        print("Erro ao capturar imagem da camera.")
        break

    frame = cv2.flip(frame, 1)
    h, w, _ = frame.shape

    rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    resultado = hands.process(rgb)

    if resultado.multi_hand_landmarks:
        hand = resultado.multi_hand_landmarks[0]
        mp_draw.draw_landmarks(frame, hand, mp_hands.HAND_CONNECTIONS)

        indicador = hand.landmark[8]

        cam_x = int(indicador.x * w)
        cam_y = int(indicador.y * h)

        mouse_x = int(indicador.x * screen_w)
        mouse_y = int(indicador.y * screen_h)

        pyautogui.moveTo(mouse_x, mouse_y, duration=0)

        cv2.circle(frame, (cam_x, cam_y), 12, (0, 255, 0), -1)

        if last_x is not None:
            distancia = math.hypot(mouse_x - last_x, mouse_y - last_y)

            if distancia < LIMITE_MOVIMENTO:
                if still_start is None:
                    still_start = time.time()

                tempo = time.time() - still_start

                cv2.putText(
                    frame,
                    f"Parado: {tempo:.1f}s",
                    (30, 50),
                    cv2.FONT_HERSHEY_SIMPLEX,
                    1,
                    (0, 255, 255),
                    2
                )

                if tempo >= TEMPO_PARADO and not clicked:
                    pyautogui.click()
                    clicked = True
                    print("CLIQUE REALIZADO")

            else:
                still_start = None
                clicked = False

        last_x, last_y = mouse_x, mouse_y

    else:
        still_start = None
        clicked = False
        last_x, last_y = None, None

        cv2.putText(
            frame,
            "Mao nao detectada",
            (30, 50),
            cv2.FONT_HERSHEY_SIMPLEX,
            1,
            (0, 0, 255),
            2
        )

    cv2.imshow("Sensor de Mao - MediaPipe", frame)

    if cv2.waitKey(1) & 0xFF == 27:
        break

cap.release()
cv2.destroyAllWindows()
