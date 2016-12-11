#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<dos.h>
#include"page.cpp"
#include"v_page.cpp"

/* function to find the hamming distance between two 2-bit numbers */
int hamdist(int temp[2],int c[128][2],int p)
{
	int met=0,t=p;
	int i;
	for(i=0;i<=1;i++)
	{
		if (c[t][i]!=temp[i])
			met++;
	}

	return(met);
}



/* function to compare a 1-D array with a given 2-D array */
int cmp(int zh[7],int s[64][6])
{
	int i,j,f=0;
	for(i=0;i<64;i++)
	{
		f=0;
		for(j=0;j<6;j++)
		{
			if(zh[j]!=s[i][j])
				f=1;
		}
		if(f==0)
			return i;
	}
	return -1;
}

/* funtion to find the bit-wise XOR of 2 bits */
int myxor(int a,int b)
{
	if((a==0&&b==0)||(a==1&&b==1))
		return (0);
	else if((a==0&&b==1)||(a==1&&b==0))
		return (1);
	else return (-1);
}
void tone(void)
{
	sound(1000);
	delay(100);
	nosound();
}

void main()
{

	char muk='0';
	char ex[80]="Created by ASHUTOSH,MUKUL,PRATEEK and GAURAV.";
	char ex1[60]= "Programming language used is : TURBO C++.";
	char ex2[50]="UNDER THE GUIDANCE:MR. CHANDAN RAI." ;
	char ex3[50]="THANK YOU FOR USING THIS SOFTWARE.";



abc:clrscr();
    page(1);
    v_page(1);
    v_page(78);
    page(23);
    int k,j,i,n,l,m,g0[7]={1,0,1,1,0,1,1},g1[7]={1,0,1,0,0,1,1},gen[100],gener[50][100],x,y=0,msg[100][100],enco[100][100],sum,encoded[100],h,noise[100],bits,received[100],opt,transmit;

    int s[64][6],z[128][7],a[128][2],c[128][2],q=0,decodedmat[100],met1=0,met2=0,p1,p2,met11x=0,met12x=0,met21x=0,met22x=0,metx[2];
    int temp1[2]={0,0},e1,e2;
    int temp[]={0,0};
    int p=0,e=0;

    n=2;
    m=6;


    gotoxy(20,4);
    textcolor(13);
    cprintf("----------------------------------------------");
    gotoxy(20,5);
    textcolor(19);
    cprintf("TRANSMISSION ERROR DETECTION AND NOISE REMOVAL");
    gotoxy(20,6);
    textcolor(13);
    cprintf("----------------------------------------------");





    /*printf("\n enter g0");
      for(i=0;i<7;i++)
      scanf("%d",&g0[i]);*/
    //g0[7]={1,0,1,1,0,1,1};
    /*printf("\n enter g1");
      for(i=0;i<7;i++)
      scanf("%d",&g1[i]);  */
    //g1[7]={1,0,1,0,0,1,1};




    gotoxy(21,8);
    textcolor(22);
    cprintf("Enter the no. of message bits:\n");
    textcolor(20);
    cscanf("%d",&l);


    x=n*(l+m);  //to find the value of the no. of columns in the generator matrix
    i=0;
    k=0;

    while((k<14)&&(i<7))
    {
	    gen[k++]=g0[i];
	    gen[k++]=g1[i++];
    }

    /* for(k=14;k<x;k++)     ****this section may be necessary
       gen[k]=0;
       for(k=0;k<x;k++)
       printf("%d",gen[k]);  */


    for(i=0;i<l;i++)
    {
	    for(j=0;j<x;j++)
	    {
		    gener[i][j]=gen[(j+x-y)%x];}
	    y=y+2;
    }          // creation of the generator matrix




    textcolor(22);
    gotoxy(21,10);
    cprintf("Enter the message elements:\n");
    for(i=0;i<1;i++){
	    for(j=0;j<l;j++){
		    textcolor(20);
		    cscanf("%d",&msg[i][j]);
	    }
    }

    for(i=0;i<1;i++)
    {
	    for(j=0;j<x;j++)
	    {
		    sum=0;
		    for(k=0;k<l;k++)
			    sum=sum+msg[i][k]*gener[k][j];
		    enco[i][j]=sum;
	    }
    }   //encoded message formed using time-domain approach

    h=0;
    for(i=0;i<1;i++)
    {
	    for(j=0;j<x;j++)
	    {
		    if(enco[i][j]%2==0)
			    encoded[h]=0;
		    else
			    encoded[h]=1;
		    h++;
	    }

    }

    gotoxy(21,13);
    textcolor(34);
    cprintf("Encoded signal is:");


    textcolor(43);
    gotoxy(21,15);
    for(j=0;j<x;j++)
    {

	    cprintf("%d",encoded[j]);
	    delay(200);
    }
    gotoxy(21,17);
    textcolor(22);
    cprintf("Press \"1\" key to transmit the encoded signal:\n");
    textcolor(19);
    cscanf("%d",&transmit);
    if(transmit!=1)
	    exit(1);

    for(j=0;j<x;j++)
	    received[j]=encoded[j];


    gotoxy(21,19);
    textcolor(22);
    cprintf("DO YOU WANT TO INCLUDE NOISE IN THE TRANSMISSION");
    gotoxy(21,20);
    cprintf("Press '1' for 'YES'; '0' for 'No':");
    textcolor(19);
    cscanf("%d",&opt);


    if(opt==1)
    {

	    gotoxy(21,22);
	    textcolor(22);
	    cprintf("Enter the no. of bits to be changed:\n");
	    gotoxy(21,1);
	    cprintf("(note:prefer to change just one bit)");
	    textcolor(20);
	    gotoxy(59,22);
	    cscanf("%d",&bits);
	    clrscr();
	    page(1);page(23);
	    v_page(1);
	    v_page(78);
	    gotoxy(21,4);
	    textcolor(22);
	    cprintf("Enter the bit no.:");
	    textcolor(20);
	    for(i=0;i<bits;i++)
	    {
		    cscanf("%d",&noise[i]);

	    }
	    for(i=0;i<bits;i++)
	    {
		    y=noise[i];
		    if(received[y]==0)
			    received[y]=1;
		    else
			    received[y]=0;
	    }
    }    //to add noise

    if(opt==0)
    {
	    clrscr();
	    page(1);
	    page(23);
	    v_page(1);
	    v_page(78);
    }
    textcolor(34);
    gotoxy(21,7);
    cprintf("The received signal at the receiver:");
    textcolor(43);

    gotoxy(21,8);
    for(j=0;j<x;j++)

    {
	    cprintf("%d",received[j]);
	    delay(100);
    }

    // the received signal at the receiver, containg noise.
    // channel assumed to be BSC
    getch();

    for(i=0;i<64;i++)
    {
	    for(j=0;j<6;j++)
	    {
		    s[i][j]=0;
	    }
    }



    for(i=0;i<64;i++)
    {
	    k=i;
	    j=5;//6-1=5
	    while(k)
	    {
		    s[i][j--]=k%2;
		    k=k/2;
	    }
    }  // creation of the S-matrix  (***state matrix)
    // here, the S-matrix is taken to be in the ascending order
    // for example, the 0th row of the matrix is 000000
    //first row is 000001 etc

    k=0;


    for(i=0;i<128;i++)
    {
	    z[i][0]=0;
	    for(j=1;j<7;j++)
		    z[i][j]=s[k][j-1];
	    i++;
	    z[i][0]=1;
	    for(j=1;j<7;j++)
		    z[i][j]=s[k][j-1];
	    k++;
    }

    for(i=0;i<128;i++)
    {
	    //printf("\n");
	    for(j=0;j<7;j++)
	    {

		    // printf("%d",z[i][j]);
	    }
	    // printf("   ");
    }


    for(i=0;i<128;i++)
    {
	    a[i][0]=i/2;
	    a[i][1]=cmp(z[i],s);
	    if(a[i][1]==-1)
	    {
		    textcolor(18);
		    clrscr();
		    gotoxy(38,10);
		    cprintf("\n error!!");
		    getchar();
		    exit(1);  //the "next-state" table is formed using the S-matrix
	    }
	    // printf("(%d,%d) \t",a[i][0],a[i][1]);
    }



    for(i=0;i<128;i++)
	    for(j=0;j<2;j++)
		    c[i][j]=0;
    for(i=0;i<128;i++)
	    for(j=0;j<7;j++)
	    {
		    if(g0[j]==1)
			    c[i][0]=myxor(c[i][0],z[i][j]);
		    if(g1[j]==1)
			    c[i][1]=myxor(c[i][1],z[i][j]);
	    }






    /*	for(i=0;i<128;i++)
	{
	for(j=0;j<2;j++)
	printf("%d",c[i][j]);
	printf("\t");
	}
	temp[0]=received[0];
	temp[1]=received[1]; //the temp array is a temporary array to hold  //the current 2 bits of the received signal
	met1=hamdist(temp,c,0);
	met2=hamdist(temp,c,1);
	if(met1<met2)
	{
	decodedmat[q]=0;
	q++;
	e=a[0][1];
	p=2*e;
	}
	else
	{
	if(met2<met1)
	{
	decodedmat[q]=1;
	q++;
	e=a[1][1];
	p=2*e;
	}
	}*/








    i=0;
    while(i<x)
    {
	    temp[0]=received[i];
	    temp[1]=received[i+1];
	    met1=hamdist(temp,c,p);
	    met2=hamdist(temp,c,p+1);
	    if(met1<met2)
	    {
		    decodedmat[q]=0;
		    q++;
		    e=a[p][1]; //calculating to which position
		    //the control must be transferred to next
		    //to continue the decoding, using the "next-state table"
		    //and the S-matrix
		    p=2*e;
		    gotoxy(21,28);
		    textcolor(16);
		    //cprintf("p=%d  ",p);
	    }
	    else
		    if(met2<met1)
		    {
			    decodedmat[q]=1;
			    q++;
			    e=a[p+1][1];
			    p=2*e;
			    //cprintf("p=%d  ",p);
		    }


	    //condition when both the outputs have the same hamming distance
	    //then, the next state for both the outputs is calculated
	    //the least hamming distance in the next path is desirable
	    //therefore the appropriate path is chosen
	    //this can be extended to the rest of the paths too,
	    //using a recursive function


		    else
		    {
			    k=i+2;
			    temp1[0]=received[k];
			    temp1[1]=received[k+1];
			    e1=a[p][1];
			    p1=2*e1;
			    e2=a[p+1][1];
			    p2=2*e2;
			    met11x=hamdist(temp1,c,p1);
			    met12x=hamdist(temp1,c,p1+1);
			    met22x=hamdist(temp1,c,p2+1);
			    met21x=hamdist(temp1,c,p2);
			    if(met11x<met12x)
				    metx[0]=met11x;
			    else
				    metx[0]=met12x;
			    if(met21x<met22x)
				    metx[1]=met21x;
			    else
				    metx[1]=met22x;

			    if(metx[0]<metx[1])
			    {
				    p=p1; decodedmat[q]=0; q++;
			    }
			    else
			    {
				    p=p2; decodedmat[q]=1;q++;
			    }




		    }



	    i=i+2;
    }
    gotoxy(21,10);
    textcolor(34);
    cprintf("The decoded output is:\n");


    textcolor(4);
    for(q=0;q<l;q++)
    {


	    cprintf("  %d",decodedmat[q]);
	    delay(100);
    }


    gotoxy(21,14);
    textcolor(12);
    cprintf("DO YOU WANT TO CONTINUE? ");
    gotoxy(21,16);
    textcolor(15);
    cprintf("PRESS 'Y' TO CONTINUE, ELSE ANY KEY:\n");
    textcolor(23);
    muk=getch();
    if(muk=='y'||muk=='Y')
	    goto abc;

    clrscr();
    page(1);
    page(23);
    v_page(1);
    v_page(79);
    for( j=0;j<55;j++)
    {
	    textcolor(13); gotoxy(20+j,10);
	    cprintf("%c",ex[j]);
	    sound(3000+j);
	    delay(30);
	    nosound();
    }
    for( m=0;m<40;m++)
    {
	    textcolor(10);  gotoxy(20+m,12);
	    cprintf("%c",ex1[m]);
	    sound(1800+m);
	    delay(30);
	    nosound();
    }

    for( k=0;k<42;k++)
    {
	    textcolor(4);  gotoxy(20+k,14);
	    cprintf("%c",ex2[k]);
	    sound(2000+k);
	    delay(30);
	    nosound();
    }

    for( l=0;l<40;l++)
    {
	    textcolor(3);  gotoxy(20+l,16);
	    cprintf("%c",ex3[l]);
	    sound(2500+l);
	    delay(30);
	    nosound();
    }



    getch();
}
