#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int process, lenM, lenK;
char message[1000], key[1000];

void processing (void) {
  scanf("%d", &process);
  switch (process) {
    //Generazione chiave
    case 1: printf("Generazione della chiave...\n\n");
            srand(time(NULL));
            sleep(1);

            for (int i = 0; i < strlen(message); i++) {
              key[i] = rand() % (127 - 31) + 31;
            }

            printf("%s\n", key);
            break;
    //Scrittura di una personale chiave
    case 2: fgets(key, strlen(message), stdin);
            lenM = strlen(message);
            lenK = strlen(key);
            while (lenK < lenM) {
              fflush(stdin);
              printf("Inserire una chiave che abbia una lunghezza uguale o superiore al messaggio \n");
              fgets(key, 128, stdin);
              lenK = strlen(key);
            }
            break;
    //Nel caso in cui il numero intero non sia nè 1, nè 2
    default : printf("\nErrore nella scelta, ripetere l'azione\n\n");
              processing();

  }
}

int main() {

  //Inserimento di un messaggio iniziale che non superi i 128 caratteri

  printf("Inserisci il messaggio da criptare, che non superi i 128 caratteri.\n");
  fgets(message, 1000, stdin);
  while(strlen(message) > 128) {
    printf("Errore, inserire un messaggio che non superi i 128 caratteri.\n");
    fgets(message, 1000, stdin);
  }

  //Scelta tra generazione della chiave e scrittura di una personale chiave

  printf("\nVuole criptare questo messaggio attraverso una chiave generata casualmente o scrivendone una da tastiera?\n\n     [[################################################]]\n     ||                                                ||\n     ||  1 : Generazione casuale di una chiave         ||\n     ||                                                ||\n     ||  2 : Scrittura di una chiave tramite tastiera  ||\n     ||                                                ||\n     [[################################################]]\n\n");

  processing();

  //Criptaggio e stampa della chiave
  printf("\nGrazie alla chiave si ha che il messaggio criptato è:\n");

  for (int i = 0; i < (strlen(key)+1); i++) {
    message[i] = message[i] ^ key[i];
    printf("%c", message[i]);
  }

  //Decriptaggio e stampa del messaggio
  printf("\n\nUtilizzando la chiave avremo invece che il messaggio decriptato è:\n\n");

  for (int i = 0; i < strlen(key); i++) {
    message[i] = key[i] ^ message[i];
    printf("%c", message[i]);
  }

  return 0;
}
