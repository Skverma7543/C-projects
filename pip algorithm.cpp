#include<iostream>
#define N 30
using namespace std;
class data
{
public:
string c1;
string c2;
double p;
}obj[N];
bool find(string x,string y)
{
for(int i=0;i<N;i++)
{
if(x==obj[i].c1&&y==obj[i].c2)
return 1;
}
return 0;
}
double price(string x,string y)
{
for(int i=0;i<N;i++)
{
if((x==obj[i].c1)&&(y==obj[i].c2))
return obj[i].p;
}
return 1;
}
void SET()
{
obj[0].c1="AUD";obj[0].c2="CAD";obj[0].p=0.9533;
obj[1].c1="AUD";obj[1].c2="CHF";obj[1].p=0.6599;
obj[2].c1="AUD";obj[2].c2="JPY";obj[2].p=75.44;
obj[3].c1="AUD";obj[3].c2="NZD";obj[3].p=1.0793;
obj[4].c1="AUD";obj[4].c2="USD";obj[4].p=0.7163;
obj[5].c1="CAD";obj[5].c2="JPY";obj[5].p=79.13;
obj[6].c1="CHF";obj[6].c2="JPY";obj[6].p=114.28;
obj[7].c1="EUR";obj[7].c2="AUD";obj[7].p=1.6360;
obj[8].c1="EUR";obj[8].c2="CAD";obj[8].p=1.5593;
obj[9].c1="EUR";obj[9].c2="CHF";obj[9].p=1.0795;
obj[10].c1="EUR";obj[10].c2="GBP";obj[10].p=0.9055;
obj[11].c1="EUR";obj[11].c2="JPY";obj[11].p=123.39;
obj[12].c1="EUR";obj[12].c2="NZD";obj[12].p=1.7654;
obj[13].c1="EUR";obj[13].c2="USD";obj[13].p=1.1716;
obj[14].c1="GBP";obj[14].c2="AUD";obj[14].p=1.8063;
obj[15].c1="GBP";obj[15].c2="CAD";obj[15].p=1.7220;
obj[16].c1="GBP";obj[16].c2="CHF";obj[16].p=1.1922;
obj[17].c1="GBP";obj[17].c2="JPY";obj[17].p=136.26;
obj[18].c1="GBP";obj[18].c2="NZD";obj[18].p=1.9498;
obj[19].c1="GBP";obj[19].c2="USD";obj[19].p=1.2938;
obj[20].c1="NZD";obj[20].c2="JPY";obj[20].p=69.88;
obj[21].c1="NZD";obj[21].c2="USD";obj[21].p=0.6637;
obj[22].c1="USD";obj[22].c2="BRL";obj[22].p=5.6833;
obj[23].c1="USD";obj[23].c2="CAD";obj[23].p=1.3309;
obj[24].c1="USD";obj[24].c2="CHF";obj[24].p=0.9214;
obj[25].c1="USD";obj[25].c2="CNY";obj[25].p=6.7908;
obj[26].c1="USD";obj[26].c2="INR";obj[26].p=73.295;
obj[27].c1="USD";obj[27].c2="JPY";obj[27].p=105.30;
obj[28].c1="USD";obj[28].c2="RUB";obj[28].p=78.1851;
obj[29].c1="USD";obj[29].c2="TRY";obj[29].p=7.7739;
}
/***********************************************************/
int main()
{
SET();
double basis=0.0001,pip,price1;
int lot_size;
string DC,x1,x2;
cout<<"enter lotsize and DC"<<endl;
cin>>lot_size;
cout<<”enter BASE currency(display currency) “<<endl;
cin>>DC;
pip=basis*lot_size;
/**************************************************************/
while(1)
{
cout<<"enter currency you have"<<endl;
cin>>x2;
if(x2==”JPY”)
{
pip=pip*100;
if(DC==”USD”||DC==”EUR”||DC==”CHF”||DC==”RUB”)
pip=pip*100;
}
if(DC==x2)
{
//pip=pip;
}
else if(find("USD",x2))
{
pip=pip/price("USD",x2);
if(DC!="USD")
{
if(find("USD",DC))
{
pip=pip*price("USD",DC);
}
else if(DC,"USD")
{
pip=pip/price(DC,"USD");
}
}
}
else if(find(x2,"USD"))
{
pip=pip*price(x2,"USD");
if(DC!="USD")
{
if(find("USD",DC))
{
pip=pip*price("USD",DC);
}
else if(DC,"USD")
{
pip=pip/price(DC,"USD");
}
}
}
else if("USD"==x2)
{
if(find("USD",DC))
{
pip=pip*price("USD",DC);
}
else if(DC,"USD")
{
pip=pip/price(DC,"USD");
}
}
else
{
cout<<"enter wrong DC write again"<<endl;
cin>>DC;
}
cout<<pip<<endl;
pip=0.0001*lot_size;
}
}
