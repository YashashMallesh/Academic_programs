Semaphore chopstick[5];
do{
  wait(chopstick[i]);
  wait(chopstick[(i+1)%5]);
  //eat
  signal(chopstick[i]);
  signal(chopstick[(i+1)%5]);
}while(TRUE);
