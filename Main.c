#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void *ping(void *arg){
    int p=0;
    for(int i=0;i<3;i++){
        sleep(1);
        printf("Ping\n");
        p++;
    }
    printf("Ping = %d", p);
}

void pong(){
    int i=0;
    while(i<1){
        sleep(2);
        printf("Pong\n");
        i++;
    }
}
int main(){
     pthread_t Ping;
    pthread_create(&Ping, NULL, ping, NULL);
    pong();
    pthread_join(Ping, NULL);
    return 0;
}