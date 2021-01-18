#include "stm32f10x.h"

void Sortie(int conf , GPIO_TypeDef* GPIO);
void Entrie(int conf , GPIO_TypeDef* GPIO) ;
void Analogique(int conf , GPIO_TypeDef* GPIO) ;
int  lire(GPIO_TypeDef* GPIO) ;
void config(int etat,GPIO_TypeDef* GPIO);
void Delay(int count);