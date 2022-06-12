
#include<iostream>
using namespace std;
void unions(int a[],int b[],int c,int k){
   int i,j;
   cout<<"Union is\n{";
   for(i=0;i<k;i++){
       cout<<b[i]<<",";
   }
   for(i=0;i<c;i++){
       for(j=0;j<k+1;j++){
           if(a[i]==b[j]){
               break;
           }
       }
       if(j==k){
           cout<<a[i]<<",";
       }
   }
   cout<<"}";
}
void intersection(int a[],int b[],int c,int k){
   int i,j;
   cout<<"Intersection is\n{";
   for(i=0;i<c;i++){
       for(j=0;j<k;j++){
           if(a[i]==b[j]){
               cout<<a[i]<<",";
               break;
           }
       }
   }
   cout<<"}";
}
void complement(int a[],int b[],int c,int k){
   int i,j;
   cout<<"Complement of A is\n{";
   for(i=0;i<c;i++){
       for(j=0;j<k;j++){
           if(a[i]==b[j]){
               break;
           }
       }
       if(j==k){
           cout<<a[i]<<",";
       }
   }
   cout<<"}";
}
void difference(int a[],int b[],int c,int k){
   int i,j;
   cout<<"A-B= is\n{";
   for(i=0;i<c;i++){
       for(j=0;j<k;j++)
       {
           if(a[i]==b[j])
           {
               break;
           }
       }
       if(j==k){
           cout<<a[i]<<",";
       }
   }
   cout<<"}";
}
void symdif(int a[],int b[],int d,int k){
   int i,j;
   int c[k],m=0;
   cout<<"Symmetric difference of A and B is\n{";
   for(i=0;i<d;i++){
       for(j=0;j<k;j++){
           if(a[i]==b[j]){
               c[m++]=a[i];
               break;
           }
       }
       if(j==k){
           cout<<a[i]<<",";
       }
   }
   for(i=0;i<k;i++){
       for(j=0;j<m;j++){
           if(b[i]==c[j]){
               break;
           }
       }
       if(j==m){
           cout<<b[i]<<",";
       }
   }
   cout<<"}";
}
int main(){
   cout<<" Menu"<<endl;
   cout<<"1.Union of two sets"<<endl;
   cout<<"2.Intersection of two sets"<<endl;
   cout<<"3.Complement of set"<<endl;
   cout<<"4.Difference of two set"<<endl;
   cout<<"5.Symmetric difference of two sets"<<endl;
   int o,i,n,c;
   cout<<"Enter option: ";
   cin>>o;
   if(o!=3){
       cout<<"Enter length of set A: ";
   }
   else{
       cout<<"Enter length of universe set: ";
   }
   cin>>n;
   int a[n];
   for(i=0;i<n;i++){
       cout<<"Enter element:";
       cin>>a[i];
   }
   if(o!=3){
       cout<<"Enter length of set B: ";
   }
   else{
       cout<<"Enter length of set A: ";
   }
   cin>>c;
   int b[c];
   for(i=0;i<c;i++){
       cout<<"Enter element:";
       cin>>b[i];
   }
   if(o==1){
       unions(a,b,n,c);
   }
   else if(o==2){
       intersection(a,b,n,c);
   }
   else if(o==3){
       complement(a,b,n,c);
   }
   else if(o==4){
       difference(a,b,n,c);
   }
   else{
       symdif(a,b,n,c);
   }
}
