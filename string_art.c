#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Q FILE*
#define _q(_) free(_)
#define U(_) return _
#define u(_) strlen(_)
#define uU(_) fclose(_)
#define uUu(_) sizeof(_)
#define UuU(_) tolower(_)
#define Uu(_,__) fopen(_,__)
#define uuu(_,__) calloc(_,__) 
#define q_(___,__,_) for(_;__;___)
#define uu(...) fprintf(__VA_ARGS__)
size_t O[]={0xF9F99,0x79797,0xF111F,0x79997,0xF1F1F,0xF1F11,0xE1D9F,0x99F99,0x22222,0x3119E,0x95159,0x1111F,0x9FF99
,0x9BFD9,0xF999F,0x79711,0xF99F8,0x79759,0x61686,0xF4444,0x9999F,0x99996,0x99FF9,0x99699,0x99644,0xF861F};int main(
int o,char* oo[]){if(o<3)U(1);int OoO,oOo,OOO;char* ooo[5];q_(oOo++,oOo<5,oOo=0)oOo[ooo]=uuu(u(1[oo])*4,uUu(char));
q_(OoO++,OoO<u(1[oo]),OoO=0)q_(,oOo-->0,oOo=5)q_(OOO++,OOO<4,OOO=0)(OoO*4+OOO)[oOo[ooo]]=O[(UuU(1[oo][OoO]))-0x61]&
(1<<(oOo*4+OOO))?182:160;Q qq=Uu(2[oo],"w");if(!qq)U(1);q_(,oOo-->0,oOo=5){q_(OOO++,OOO<u(1[oo])*4,OOO=0){if(!(OOO%
4))uu(qq," ");uu(qq,"%c",(OOO)[oOo[ooo]]);}uu(qq,"\n");}uU(qq);q_(oOo++,oOo<5,oOo=0)_q(oOo[ooo]);U(0);}//(c)Bernitz
