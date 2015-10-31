/**
 * @mainpage  Tranductor Simple V1.0
 *
 *            Es un pequeño traductor que ofrece una pequeña interfaz para la traducción de palabras y frases.
 *            Su implementación se basa en el desarrollo de dos tipos de datos abstractos, Palabra y Traductor.
 *            La fuente de información de traducciones se proporciona al programa en su ejecución y será un fichero escrito en
 *            formato estilo CSV (donde las palabras están separadas por ; y cada linea conforma una entidad palabra en idioma origen seguida
 *            de palabras en idioma destino) con un formato similar a este:
 *
 *            <p/>entender;understand;realize;
 *
 *            Aunque en sí el centro lógico está en Traductor podemos ver el bucle infinito para interactuar con el usuario donde
 *            se ve el uso del traductor en pruebatraductor.cpp
 *
 *             @include pruebatraductor.cpp
 *             <p/> <br/>
 *
 *            En la implementación se ha optador por relalizar la gestión de memoria en algunos casos y en otros usar
 *            vector de la STL aunque podría haberse realizado con cualquiera de las dos opciones, ya que se trata
 *            de un problema muy sencillo.
 */
