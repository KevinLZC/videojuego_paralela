#ifndef DualCore_h
#define DualCore_h

#define NUCLEO_SECUNDARIO 0X00     // Núcleo secundario.
#define NUCLEO_PRINCIPAL  0X01     // Núcleo principalmente utilizado por el IDE en el loop original.

/* INSTANCIAS FREE-RTOS */
TaskHandle_t Hilo1;
TaskHandle_t Hilo2;

TaskHandle_t Hilo3;
TaskHandle_t Hilo4;

TaskHandle_t Hilo5;
TaskHandle_t Hilo6;
TaskHandle_t Hilo7;
TaskHandle_t Hilo8;

TaskHandle_t Hilov1;
TaskHandle_t Hilov2;
TaskHandle_t Hilov3;

class DualCoreESP32 {

  public:
    void ConfigCores ( void );



  private:
    static void Loop1 ( void *pvParameters );
    static void Loop2 ( void *pvParameters );
    /*  Actividad B.  */
    static void New_Loop1 ( void *pvParameters );
    static void New_Loop2 ( void *pvParameters );

    static void Loopv1 ( void *pvParameters );
    static void Loopv2 ( void *pvParameters );
    static void Loopv3 ( void *pvParameters );

    /*  Variables  */
    // void *milli_task1;
    static uint64_t tiempo_anterior_task1 ,
            tiempo_anterior_task2 ,
            tiempo_anterior_task3 ,
            tiempo_anterior_task4 ,
            tiempo_actual;
    

};

void DualCoreESP32 :: ConfigCores ( void ) {

  xTaskCreatePinnedToCore (
    this->Loopv1,            /* Función que controla la tarea. */
    "CiclovTask1",               /* Etiqueta de la tarea.          */
    1000,                   /* Tamaño en memoria RAM.         */
    NULL,                   /* Parametros de la tarea.        */
    1,                      /* Prioridad de la tarea.         */
    &Hilov1,                 /* Seguimiento de la tarea.       */
    NUCLEO_SECUNDARIO       /* Número de núcleo.              */
  );
  xTaskCreatePinnedToCore (
    this->Loopv2,            /* Función que controla la tarea. */
    "CiclovTask2",               /* Etiqueta de la tarea.          */
    1000,                   /* Tamaño en memoria RAM.         */
    NULL,                   /* Parametros de la tarea.        */
    1,                      /* Prioridad de la tarea.         */
    &Hilov2,                 /* Seguimiento de la tarea.       */
    NUCLEO_SECUNDARIO       /* Número de núcleo.              */
  );
  xTaskCreatePinnedToCore (
    this->Loopv3,            /* Función que controla la tarea. */
    "CiclovTask3",               /* Etiqueta de la tarea.          */
    1000,                   /* Tamaño en memoria RAM.         */
    NULL,                   /* Parametros de la tarea.        */
    1,                      /* Prioridad de la tarea.         */
    &Hilov3,                 /* Seguimiento de la tarea.       */
    NUCLEO_SECUNDARIO       /* Número de núcleo.              */
  );
//   vTaskSuspend(Hilov2);
//   vTaskSuspend(Hilov3);


  // xTaskCreatePinnedToCore (
  //   this->Loop1,            /* Función que controla la tarea. */
  //   "Ciclo1",               /* Etiqueta de la tarea.          */
  //   1000,                   /* Tamaño en memoria RAM.         */
  //   NULL,                   /* Parametros de la tarea.        */
  //   1,                      /* Prioridad de la tarea.         */
  //   &Hilo1,                 /* Seguimiento de la tarea.       */
  //   NUCLEO_SECUNDARIO       /* Número de núcleo.              */
  // );

  // xTaskCreatePinnedToCore (
  //   this->Loop2,            /* Función que controla la tarea. */
  //   "Ciclo2",               /* Etiqueta de la tarea.          */
  //   1000,                   /* Tamaño en memoria RAM.         */
  //   NULL,                   /* Parametros de la tarea.        */
  //   1,                      /* Prioridad de la tarea.         */
  //   &Hilo2,                 /* Seguimiento de la tarea.       */
  //   NUCLEO_PRINCIPAL        /* Número de núcleo.              */
  // );


}

void DualCoreESP32 :: Loopv1 ( void * pvParameters ) {

  const TickType_t xDelay = 1000 / portTICK_PERIOD_MS;
  for(;;){
    String sentence =  "Tarea v1 ejecutada en el procesador: "+ ((String)xPortGetCoreID());

    // Serial.print ( F ( "Tarea 1 ejecutada en el procesador: " ) );
    // Serial.println( xPortGetCoreID );
    Serial.println ( sentence );

    /*  Actividad B  */
    // delay ( 10 );

    /*   Actividad C   */ 
    // delay ( 1000 );
    vTaskDelay(xDelay);
    vTaskResume(Hilov2);
    vTaskSuspend(NULL);

    // vTaskDelete(NULL); // Eliminar una tarea

  }
}

void DualCoreESP32 :: Loopv2 ( void * pvParameters ) {


const TickType_t xDelay = 1000 / portTICK_PERIOD_MS;
  for(;;){
    String sentence =  "Tarea v2 ejecutada en el procesador: "+ ((String)xPortGetCoreID());

    // Serial.print ( F ( "Tarea 1 ejecutada en el procesador: " ) );
    // Serial.println( xPortGetCoreID );
    Serial.println ( sentence );

    /*  Actividad B  */
    // delay ( 10 );

    /*   Actividad C   */
    // delay ( 1000 );
    vTaskDelay(xDelay);
    vTaskResume(Hilov3);
    vTaskSuspend(NULL);
    
    // vTaskDelete(NULL); // Eliminar una tarea

  }
}

void DualCoreESP32 :: Loopv3 ( void * pvParameters ) {

  const TickType_t xDelay = 1000 / portTICK_PERIOD_MS;
  for(;;){
    String sentence =  "Tarea v3 ejecutada en el procesador: "+ ((String)xPortGetCoreID());

    // Serial.print ( F ( "Tarea 1 ejecutada en el procesador: " ) );
    // Serial.println( xPortGetCoreID );
    Serial.println ( sentence );

    /*  Actividad B  */
    // delay ( 10 );

    /*   Actividad C   */
    // delay ( 1000 );

    vTaskDelay(xDelay);
    vTaskResume(Hilov1);
    vTaskSuspend(NULL);

    // vTaskDelete(NULL); // Eliminar una tarea

  }
}

void DualCoreESP32 :: Loop1 ( void * pvParameters ) {

  for(;;){
    String sentence =  "Tarea 1 ejecutada en el procesador: "+ ((String)xPortGetCoreID());

    // Serial.print ( F ( "Tarea 1 ejecutada en el procesador: " ) );
    // Serial.println( xPortGetCoreID );
    Serial.println ( sentence );

    /*  Actividad B  */
    // delay ( 10 );

    /*   Actividad C   */
    delay ( 1000 );

    // vTaskDelete(NULL); // Eliminar una tarea

  }
}

void DualCoreESP32 :: Loop2 ( void * pvParameters ) {

  for(;;){
    String sentence = "Tarea 2 ejecutada en el procesador: " + ((String) xPortGetCoreID());

    // Serial.print ( F ( "Tarea 2 ejecutada en el procesador: " ) );
    // Serial.println( xPortGetCoreID );
    Serial.println ( sentence );
    /*  Actividad B  */
    // delay ( 10 );
    /*   Actividad C   */
    delay ( 1000 );
      
  }
}



DualCoreESP32 DCESP32;           // Instancia de la clase DualCoreESP32.
#endif