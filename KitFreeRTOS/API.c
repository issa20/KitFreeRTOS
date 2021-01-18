#include "stm32f10x.h"
#include "API.h"

void Sortie(int conf , GPIO_TypeDef* GPIO){
	RCC->APB2ENR = RCC->APB2ENR | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN| RCC_APB2ENR_IOPCEN;
	int T[16] ;
	int count=0 ,etat=0;
	
	for(int i=0;i<16;i++){
		etat=conf & (0x1<<i) ;
		if(etat){
			T[count]=i;
			count++;
			etat=0;			
		}
	}
	for(int i=0;i<count;i++){
		if(T[i]<8){
			GPIO->CRH = GPIO->CRH & ~(0xF <<(T[i]*4))  ; 			// Mise à 0 des bits b11 b10 b9 b8
			GPIO->CRH = GPIO->CRH | (0x1 << (T[i]*4+1)); 				// Mise à 1 du bit b8
		}
		else {
			GPIO->CRH = GPIO->CRH & ~(0xF <<((T[i]-8)*4))  ; 			// Mise à 0 des bits b11 b10 b9 b8
			GPIO->CRH = GPIO->CRH | (0x1 << ((T[i]-8)*4+1)); 
		}
	}
	
}

void Entrie(int conf , GPIO_TypeDef* GPIO){
	RCC->APB2ENR = RCC->APB2ENR | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN| RCC_APB2ENR_IOPCEN;
	int T[16] ;
	int count=0 ,etat=0;
	
	for(int i=0;i<16;i++){
		etat=conf & (0x1<<i) ;
		if(etat){
			T[count]=i;
			count++;
			etat=0;			
		}
	}
	for(int i=0;i<count;i++){
		if(T[i]<8){
			GPIO->CRH = GPIO->CRH & ~(0xF <<(T[i]*4))  ; 			// Mise à 0 des bits b11 b10 b9 b8
			GPIO->CRH = GPIO->CRH | (0x1 << (T[i]*4+3)); 				// Mise à 1 du bit b8
		}
		else {
			GPIO->CRH = GPIO->CRH & ~(0xF <<((T[i]-8)*4))  ; 			// Mise à 0 des bits b11 b10 b9 b8
			GPIO->CRH = GPIO->CRH | (0x1 << ((T[i]-8)*4+3)); 
		}
	}
	
}

void Analogique(int conf , GPIO_TypeDef* GPIO){
	RCC->APB2ENR = RCC->APB2ENR | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN| RCC_APB2ENR_IOPCEN;
	int T[16] ;
	int count=0 ,etat=0;
	
	for(int i=0;i<16;i++){
		etat=conf & (0x1<<i) ;
		if(etat){
			T[count]=i;
			count++;
			etat=0;			
		}
	}
	for(int i=0;i<count;i++){
		if(T[i]<8){
			GPIO->CRH = GPIO->CRH & ~(0xF <<(T[i]*4))  ; 			// Mise à 0 des bits b11 b10 b9 b8
			//GPIO->CRH = GPIO->CRH | (0x1 << (T[i]*4+3)); 				// Mise à 1 du bit b8
		}
		else {
			GPIO->CRH = GPIO->CRH & ~(0xF <<((T[i]-8)*4))  ; 			// Mise à 0 des bits b11 b10 b9 b8
			//GPIO->CRH = GPIO->CRH | (0x1 << ((T[i]-8)*4+3)); 
		}
	}
	
}
int  lire(GPIO_TypeDef* GPIO){
return GPIO->IDR ;
}
void config(int etat,GPIO_TypeDef* GPIO){
int conf ;
for(int i=0;i<16;i++){
		conf=etat & (0x1<<i) ;
		if(conf){
			GPIO->BSRR |=(0x1<<i);		
		}
		else {
			GPIO->BRR |=(0x1<<i);
	}
}
}

void Delay(int count){
while(count--) ;
}

