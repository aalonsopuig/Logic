# Logic
 [C] 1989. Analizador lógico básico en PC. Por Alejandro Alonso Puig
<BR><BR>
Este sencillo programa tiene como única finalidad representar de una
forma basta los impulsos digitales que entran por el pin 15 (Error/Fault) 
del puerto paralelo LPT1, no pretende ser un analizador lógico. El muestreo
comienza cuando la señal de entrada cambia de estado.<BR><BR>
  La frecuencia de muestreo depende del ordenador en el que se ejecute.
Si esta frecuencia no es la correcta, se puede modificar el código
fuente para utilizar un retardo mayor.<BR><BR>
  La representación gráfica se realiza utilizando la librería "egavga.bgi"
de Borland, que deberá estar presente en el mismo directorio que el 
ejecutable.<BR><BR>
  Para salir hay que pulsar "ESC". El programa finalizará tras el siguiente
muestreo. 
