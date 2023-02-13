 #include<stdio.h> 
int x,y,z,a[10],b[10],b1[10],b2[10],b2c[10],u[10],d=0,o=1; 
void Union() { 
printf("\nA Union B : "); 
for (int i=0;i<10;i++) { 
printf("%d",b1[i] | b2[i]); 
} 
} 
void Intersection() { 
printf("\nA Intersection B : "); 
for (int i=0;i<10;i++) { 
printf("%d",b1[i] * b2[i]); 
} 
} 
void Diff() { 
for (int i=0;i<10;i++) { 
if(b2[i]==0) { 
b2c[i]=1; 
} else { 
b2c[i]=0; 
} 
} 
printf("\nA - B : "); 
for (int i=0;i<10;i++) { 
printf("%d",b1[i] * b2c[i]); 
} 
} 
void main() { 
printf("Enter the number of elements in set U\n"); 
scanf("%d",&x); 
printf("Enter the elements in set U\n"); 
for (int i=0;i<x;i++) { 
scanf("%d",&u[i]); 
}

printf("Enter the number of elements in set A 
\n"); 
scanf("%d",&y); 
printf("Enter the elements in set A 
\n"); 
for (int i=0;i<y;i++) { 
scanf("%d",&a[i]); 
} 
printf("Enter the number of elements in set B 
\n"); 
scanf("%d",&z); 
printf("Enter the elements in set B 
\n"); 
for (int i=0;i<z;i++) { 
scanf("%d",&b[i]); 
} 
for (int i=0;i<x;i++) { 
for (int j=0;j<y;j++) { 
if(a[j]==u[i]) { 
b1[i]=1; 
break; 
} else { 
b1[i]=0; 
} 
} 
} 
for (int i=0;i<x;i++) { 
for (int j=0;j<z;j++) { 
if(b[j]==u[i]) { 
b2[i]=1; 
break; 
} else { 
b2[i]=0; 
} 
} 
} 
printf(" 
\nA : "); 
for (int i=0;i<10;i++) { 
printf("%d",b1[i]); 
} 
printf(" 
\nB : "); 
for (int i=0;i<10;i++) { 
printf("%d",b2[i]); 
}


while(o==1) { 
printf("\nEnter any option \n1.Union\n2.Intersection\n3.Difference\n"); 
scanf("%d",&d); 
switch(d) { 
case 1 : Union(); 
printf("\n"); 
break; 
case 2 : Intersection(); 
printf("\n"); 
break; 
case 3 : Diff(); 
printf("\n"); 
break; 
} 
printf("Continue(0/1)"); 
scanf("%d",&o); 
} 
}