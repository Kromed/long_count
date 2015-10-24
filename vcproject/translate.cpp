#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

string translate(signed long d,int m,signed long yy)
{
              

              int feb=0, ysz=0;                                 //���������� ��� �������� ��������� ������������� ���� �� ���
              signed int winal=0,tun=0,katun=0,bactun=0,sun=0;  //���������� ��� ��������� ���� � ���� �������� �����
	          signed long y,kin=0;
	          signed long z=0,dz=0, xdz=0,ydz=0;                 //���������� ��� ������� ��������
	          signed long h=0,dh=0,xdh=0,ydh=0;                  //���������� ��� ������� �����
	          char *zydz,*zydh;                                 //��� ���������� ����� � �������� ������
	          y=yy;                                             //���������� ����

              //������1: �������� ������������ ���� �� ������������

              if(y<0) y=y-3;
			  if(!(y%400)){feb=1; goto oun;}
			  if(!(y%100)){feb=0;goto oun;}
			  if(!(y%4)){feb=1;goto oun;}
			  feb=0;
			  oun:
			  if(y<0) y=y+3;

			  //������2: ������� ����� ���� � ����������� ���� 

				switch (m) 
							{
							case 01&1 : {d=d+0;} break;
							case 02&2 : {d=d+31;} break;
							case 03&3 : {d=(d+59+feb);} break; 
							case 04&4 : {d=(d+90+feb);} break;
							case 05&5 : {d=(d+120+feb);} break;
							case 06&6 : {d=(d+151+feb);} break;
							case 07&7 : {d=(d+181+feb);} break;
							case '08' &8 : {d=(d+212+feb);} break;  //bug
							case '09' &9 : {d=(d+243+feb);} break;  //bug
							case 10 : {d=(d+273+feb);} break;
							case 11 : {d=(d+304+feb);} break;
							case 12 : {d=(d+334+feb);} break;
							}

				//������ ����������� ������ ��� ��� ���� �� ����� ���

				if (y<0) {
						 if(feb==1){d=367-d;}
						 else {d=366-d;}
						 d=-d;
						 } 

				//������3: ������� ����� ���� � ����� ����� ����������� �� 1 ���� ����� ���.

				if (y<0)
					  {
						  y=y+1;
						  if (y==0){feb=1; goto oud;}
						  for (y; y < 0; y++)                      //����� ����������� ��� ���� �� ������ �� 1 �.�.�.
									{     
									   	y=y-3;                     //�������� ������� ������������ � ������ ���������� 0 ����
										if(!(y%400)){ysz=366; goto oud;}
										if(!(y%100)){ysz=365;goto oud;}
										if(!(y%4)){ysz=366;goto oud;}
										ysz=365;
									    oud:                                      //����� ���������� �������� ������������
										d=d-ysz;                                 //������� ����
										y=y+3;                  //�������������� �
								    }
	 
					  }
				else 
					  {
					  y=y-1;   //������� ��� �� �����������
					  if (y==0){feb=0; goto ou;}
				      for (y; y > 0; y--)                      //����� ����������� ��� ���� �� ������ �� 1 �.�.�.
									{
									if(!(y%400)){ysz=366; goto ou;}
									if(!(y%100)){ysz=365;goto ou;}
									if(!(y%4)){ysz=366;goto ou;}
									ysz=365;
									ou:                                      //����� ���������� �������� ������������
									d=d+ysz;                                 //������� ����
									}

					  }

				//������4: �������� ����������� ����� ���� � ������� �������� �����

				winal=(d/20);
				kin=(d-(winal*20));
				tun=(winal/18);
				winal=(winal-(tun*18));
				katun=(tun/20);
				tun=(tun-(katun*20));
				bactun=(katun/20);
				katun=(katun-(bactun*20));
				sun=(bactun/13);
				bactun=(bactun-(sun*13));

				//������5: ���������� �� 1 ��� ����� ��� (5 ������, ������7.�����17.���19.�����2.���10) �������, -7 winal -10 kin// 7 17 18 13 0


				if(yy>0){kin = kin+0;}
				else{kin=kin+21;winal--;}
				if (kin>19) {kin=kin-20; winal++;}

				if(yy>0){winal=winal+13;}
				else{winal=winal+31;tun--;}
				if (winal>17) {winal=winal-18; tun++;}

				if(yy>0){tun=tun+18;}
				else{tun=tun+38;katun--;}
				if (tun>19) {tun=tun-20; katun++;}

				if(yy>0){katun=katun+17;}
				else{katun=katun+37;bactun--;}
				if (katun>19) {katun=katun-20; bactun++;}


				if(yy>0){bactun=bactun+7;}
				else{bactun=bactun+20;sun--;}
				if (bactun>12) {bactun=bactun-13,sun++;}

				sun=sun+5;

				//������6: ������ ��������

				if (yy<0) {d=d+61;}
				else{d=d+60;}// ���������� �� 1 ������ 1 ���� ����� ��� (210 ���)

				z = d/260;                        
				dz=(d-(z*260));//������������ ����� ���������
				if (dz==0){dz=260;}                        
				if(dz<0)dz=260+dz;

				xdz=dz/13;                              
				xdz=(dz-(xdz*13));//�������� ������ ��� ��������
				if (xdz==0) {xdz=13;}
				if (xdz<0){xdz=-xdz;}//������

				ydz=dz/20;
				ydz=(dz-(ydz*20));//�������� �������� ��� ��������
				if (ydz==0) {ydz=20;}
				if (ydz<0){ydz=-ydz;}//������
				switch (ydz)  //����������� �������� ��� ��������
							{
							case 1: {zydz="Imix";} break;
							case 2: {zydz="Ik";} break;
							case 3: {zydz="Akbal";} break;
							case 4: {zydz="Kan";} break;
							case 5: {zydz="Chikchan";} break;
							case 6: {zydz="Kimi";} break;
							case 7: {zydz="Manik";} break;
							case 8: {zydz="Lamat";} break;
							case 9: {zydz="Muluk";} break;
							case 10: {zydz="Ok";} break;
							case 11: {zydz="Chumen";} break;
							case 12: {zydz="Eb";} break;
							case 13: {zydz="Ben";} break;
							case 14: {zydz="Ix";} break;
							case 15: {zydz="Men";} break;
							case 16: {zydz="Kib";} break;
							case 17: {zydz="Kaban";} break;
							case 18: {zydz="Etznab";} break;
							case 19: {zydz="Kawak";} break;
							case 20: {zydz="Ajaw";} break;
							}   

				//������7: ������ �����
				if (yy<0) {d=(d-211-65);}
				else{d=(d-210-66);}//���������� -210 ���������� ���������� ��������, -66 ���������� �����

				h = d/365; 
				dh=(d-(h*365));//������ ����� ����� ������
				if (dh==0){dh=365;}
				if (dh<0) {dh=365+dh;}

				xdh = dh/20; 
				xdh=(dh-(xdh*20));//������ ����� ����� �������
				if (xdh==0){xdh=20;}

				xdh--;//��������� � 0

				ydh=(dh-1)/20;//����� �����

				switch (ydh)
					        {
							case 0: {zydh="Pop";} break;
							case 1: {zydh="Wo";} break;
							case 2: {zydh="Sip";} break;
							case 3: {zydh="Sotz";} break;
							case 4: {zydh="Sek";} break;
							case 5: {zydh="Xul";} break;
							case 6: {zydh="Yaxk'in";} break;
							case 7: {zydh="Mol";} break;
							case 8: {zydh="Ch'en";} break;
							case 9: {zydh="Yax";} break;
							case 10: {zydh="Sak'";} break;
							case 11: {zydh="Keh";} break;
							case 12: {zydh="Mak";} break;
							case 13: {zydh="Kankin";} break;
							case 14: {zydh="Muwan'";} break;
							case 15: {zydh="Pax";} break;
							case 16: {zydh="K'ayab";} break;
							case 17: {zydh="Kumk'u";} break;
							case 18: {zydh="Wayeb";} break;
							}

				char buf[16];

				sprintf(buf,"%d",sun);
				std::string st=buf;
				sprintf(buf,"%d",bactun);
				st=st+" Sun "+buf;
				sprintf(buf,"%d",katun);
				st=st+" bactun "+buf;
				sprintf(buf,"%d",tun);
				st=st+" katun "+buf;
				sprintf(buf,"%d",winal);
				st=st+" tun "+buf;
				sprintf(buf,"%d",kin);
				st=st+" winal "+buf;
				sprintf(buf,"%d",xdz);
				st=st+" kin,"+buf;
				st=st+" "+zydz;
				sprintf(buf,"%d",xdh);
				st=st+","+buf;
				st=st+" "+zydh;

				return st;
}