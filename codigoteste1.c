# include < Wire .h >
# include " paj7620 .h"

// Pinos I2C do ESP32
# define SDA_PIN 21
# define SCL_PIN 22

void setup () {
Serial . begin (115200) ;
Wire . begin ( SDA_PIN , SCL_PIN ) ;

Serial . println (" Inicializando sensor PAJ7620 ...") ;

// Inicializa o sensor
if ( paj7620Init () ) {
Serial . println (" Erro ao inicializar o PAJ7620 .") ;
while (1) ; 
}

Serial . println (" PAJ7620 inicializado com sucesso .") ;
delay (100) ;

}

void loop () {
uint8_t data = 0;

// Le o registrador principal de gesto
paj7620ReadReg (0 x43 , 1 , & data ) ;

if ( data != 0) {
switch ( data ) {
case GES_RIGHT_FLAG :
Serial . println (" Gesto detectado : DIREITA ") ;
break ;

case GES_LEFT_FLAG :
Serial . println (" Gesto detectado : ESQUERDA ") ;
break ;

case GES_UP_FLAG :
Serial . println (" Gesto detectado : CIMA ") ;
break ;

case GES_DOWN_FLAG :
Serial . println (" Gesto detectado : BAIXO ") ;
break ;

case GES_FORWARD_FLAG :
Serial . println (" Gesto detectado : FRENTE ") ;
break ;

case GES_BACKWARD_FLAG :
Serial . println (" Gesto detectado : TRAS ") ;
break ;

case GES_CLOCKWISE_FLAG :
Serial . println (" Gesto detectado : SENTIDO HORARIO") ;
break ;

case GES_COUNT_CLOCKWISE_FLAG :

Serial . println (" Gesto detectado : SENTIDO ANTI - HORARIO ") ;
break ;

case GES_WAVE_FLAG :
Serial . println (" Gesto detectado : ONDA ") ;
break ;

default :
Serial . println (" Gesto desconhecido .") ;
break ;
}
}

delay (100) ;
}
