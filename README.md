# Proyecto #1 - C! 
Instituto Tecnológico de Costa Rica \
Área de Ingeniería en Computadores\
Algoritmos y Estructuras de Datos II (CE 2103)\
Segundo Semestre 2017 

## Objetivo General 
➔ Diseñar e implementar un ambiente de programación para el pseudo lenguaje C! junto con un
manejador de memoria para el mismo. \
## Objetivos Específicos 
➔ Aplicar conceptos de manejo de memoria. \
➔ Investigar y desarrollar una aplicación en el lenguaje de programación C++ \
➔ Investigar acerca de programación orientada a objetos en C++. \
➔ Aplicar patrones de diseño en la solución de un problema. \

# Descripción del Problema 
El proyecto consiste en el diseño e implementación de un IDE para el pseudo lenguaje C!. \
A continuación se explica cada una de estas secciones. \
● El editor de C!: Es un editor de texto que permite ingresar el código de C!. C! tiene una sintaxis
derivada del lenguaje C. A no ser que se indique lo contrario, se asumen las mismas reglas que el
lenguaje de programación C. Más adelante se explican algunas reglas diferentes en C!. \

El IDE interpreta y ejecuta el código C! cuando se presiona el botón Run. La ejecución se hace de
manera detenida al estilo de depuración. El usuario podrá detener la ejecución o avanzar línea por
línea (El estudiante definirá los botones que hagan esto).
En caso de que el IDE detecte un error de sintaxis o semántico, la ejecución del programa se detiene y
se muestra el error en stdout. 
● Stdout: Es la sección directamente bajo el editor. Cumple la función de standard output. Si el código C!
contiene llamadas a printf, print, cout o cualquier función similar (puede ser definida por el
estudiante), el resultado se imprime en esta sección. \
● Application Log: En esta sección se debe mostrar el log del IDE, es decir cualquier error interno,
cualquier llamada al servidor de memoria, todo lo que ocurre internamente, se mostrará en esta
sección. (Investigar el uso de algún framework de logging en C++ similar a Log4j). \
● RAM Live View: En esta sección se ve en tiempo real, el estado del RAM conforme cada línea de C! se
ejecuta. Este vista consulta constantemente al servidor de RAM para obtener el estado de la memoria
y lo pinta en pantalla. Muestra al menos los siguientes datos: \
○ Dirección de la memoria \
○ Valor \
○ Etiqueta \
○ Conteo de referencias. \
# Sobre el manejo de memoria 
Se debe diseñar e implementar un servidor que administra la memoria. El flujo en términos generales es el
siguiente: \
● Se ejecuta un programa denominado mserver indicando como parámetros el puerto en el que escucha
y el tamaño en bytes de la memoria total. \
● El servidor realiza un único malloc de la memoria total. El servidor tiene un mapa interno del bloque
entero de memoria. Por ejemplo, al iniciar puede reservar 10 MB de memoria real. Con cada petición
recibida de C!, el servidor maneja offsets para determinar la posición de cada variable de C! dentro del
bloque de memoria real. \
● El servidor escucha peticiones de C! IDE enviados en formato JSON (el contenido de las peticiones es
definido por el estudiante). Cuando C! IDE envía una petición debe indicar al menos el tipo de datos, el
nombre de la variable (si aplica) y el tamaño que se deberá reservar. \
● El servidor maneja la memoria automáticamente. Es decir, C! nunca tiene que liberar memoria o
solicitar la creación de la misma. \
● El servidor lleva el conteo de referencias y cada cierto tiempo ejecuta el garbage collector que elimina
los espacios de memoria que no son referenciados.
