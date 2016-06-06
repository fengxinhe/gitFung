//
//  main.cpp
//  tpro
//
//  Created by fengxinhe on 14-5-22.
//  Copyright (c) 2014年 fengxinhe. All rights reserved.
//  1352959 main.cpp

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include<iomanip>

using namespace std;


class Item                           //item类，包含商品数据的各项信息
{
public:
    long item_index;
    string item_name;
    string item_parea;
    double item_price;
    long item_num;
    Item* pItem;
    
public:
    //Item()=default;
    Item(long a,string b,string c,double d):
    item_index(a),item_name(b),item_parea(c),item_price(d){}
    Item(long a,long b)
    {
        item_index=a;
        item_num=b;
    }
    ~Item(){}
    long get_item_index()
    {
        return item_index;
    }
    string get_item_name()
    {
        return item_name;
    }
    string get_item_parea()
    {
        return item_parea;
    }
    double get_item_price()
    {
        return item_price;
    }
    Item *clone()
    {
        return new Item(item_index,item_name,item_parea,item_price);
        
    }
    
};
typedef struct tagStoreElement
{
    Item *pitem;
    long iNum;
}storeElement,*pstoreElement;
/*------------------------------------------------======--------------------===========---------------*/
class Store                              //store类，包含对基础商品数据的存储和处理
{
private:
    vector<pstoreElement> SEStore;
public:
    Store(){}
    ~Store(){}
    
public:
    long findGood(long);
    vector<pstoreElement>* getAllgood();
    pstoreElement getGood(long);
    void basket_print();
    bool add_good(Item*,long);
    
};


bool Store::add_good(Item* pitem, long iNum)
{
    //int size=SEStore.size();
    bool exit=false;
    if (!exit) {
        pstoreElement p=new storeElement;
        p->pitem=pitem;
        p->iNum=iNum;
        SEStore.push_back(p);
    }
    for (int x=0; x<SEStore.size(); x++) {
        pstoreElement pse=SEStore[x];
        if (pse->pitem!=NULL&&pse->pitem->get_item_index()==pitem->get_item_index()) {
            exit=true;
            pse->iNum+=iNum;
        }
    }
    return exit;
}

long Store::findGood(long index)
{
    for (int i=0; i<SEStore.size(); i++) {
        pstoreElement pse=SEStore[i];
        if (pse->pitem!=NULL&&pse->pitem->get_item_index()==index) {
            return pse->iNum;
        }
    }
    return NULL;
}

vector<pstoreElement>* Store::getAllgood()
{
    return &SEStore;
}

pstoreElement Store::getGood(long index)
{
    for (int i=0; i<SEStore.size(); i++) {
        pstoreElement pse=SEStore[i];
        if (pse->pitem!=NULL&&pse->pitem->get_item_index()==index) {
            return pse;
        }
    }
    return NULL;
}

void Store::basket_print()
{
	ofstream ofile_2("/Users/dingpeien/Desktop/t_out.txt",ios::app);
    cout<<"good name"<<setw(15)<<' '<<"good produce area"<<setw(15)<<"good price"<<endl;
    ofile_2<<"--------------------SHOPPING    LIST----------------------"<<endl;
    ofile_2<<"good name"<<setw(20)<<"good produce area"<<setw(15)<<"good price"<<endl;
    for (int i=0; i<SEStore.size(); i++) {
        ofile_2<<setw(15);       cout<<setw(5);
        ofile_2<<SEStore[i]->pitem->get_item_name();
        cout<<SEStore[i]->pitem->get_item_name();    ofile_2<<setw(20);
        cout<<setw(25);     ofile_2<<SEStore[i]->pitem->get_item_parea();
        cout<<SEStore[i]->pitem->get_item_parea();
        ofile_2<<setw(15)<<setiosflags(ios::fixed)<<setprecision(2)<<SEStore[i]->pitem->get_item_price()<<endl;
        cout<<setw(20)<<setiosflags(ios::fixed)<<setprecision(2)<<SEStore[i]->pitem->get_item_price()<<endl;
    }
    ofile_2.close();
    
}

Store* prepareStore()
{
    ifstream ifile_1("/Users/dingpeien/Desktop/t_in_item.txt");
    Store*newStore=new Store();
    long code;
    string name;
    string area;
    double price;
    while (ifile_1) {
        ifile_1>>code>>name>>area>>price;
        Item *pitem=new Item(code,name,area,price);
        newStore->add_good(pitem, 1000);
    }
    ifile_1.close();
    return newStore;
}
/*---------------m==============================================================================*/

/*===============00000=============================================================================*/
class Member
{
public:
    long member_index;
    string member_name;
    string member_gender;
    long member_phone;
    string member_rank;
    long double member_points;
public:
    Member(long a,string b,string c,long d,string e,long f):
    member_index(a),member_name(b),member_gender(c),member_phone(d),member_rank(e),member_points(f){}
    Member(){}
    ~Member(){}
	Member *clone()
	{
		return new Member(member_index,member_name,member_gender,member_phone,member_rank,member_points);
	}
    long get_member_index(){return member_index;}
    string get_member_name(){return member_name;}
    string get_member_gender(){return member_gender;}
    long get_member_phone(){return member_phone;}
    string get_member_rank(){return member_rank;}
    long double get_member_points(){return member_points;}
};
typedef struct tagMemberElement
{
	Member *pmember;
	long double mpoints;
    long mindex;
    string mname;
    string mgender;
    long mphone;
    string mrank;
}memberElement,*pmemberElement;
/*==========================================================================================＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝===========*/
class memberStore
{
private:
	vector<pmemberElement> SMStore1;
public:
	memberStore(){}
	~memberStore(){}
	long find_member(long);
    vector<pmemberElement>*getallMember(){return &SMStore1;}
	pmemberElement getMember(long);
	bool add_member(Member*,long double,long,string,string,long,string);
	void member_print(long);
	string find_member_rank(long);
    //void memberReset();
};
/*void memberStore::memberReset()
{
	ofstream ofile_3("/Users/dingpeien/Desktop/member_out.txt");
    //vector<pmemberElement>*pme=aMember->getallMember();
    for (long i=0; i<SMStore1.size()-1; i++) {
        pmemberElement pe=SMStore1[i];
        ofile_3<<pe->mindex<<' '<<pe->mname<<' '<<pe->mgender<<' '<<pe->mphone<<' '<<pe->mrank<<' '<<pe->mpoints<<endl;
    }}*/
bool memberStore::add_member(Member*pmem,long double mpoint,long index,string name,string gender,long phone,string rank)
{
	pmemberElement p=new memberElement;
	p->pmember=pmem;
    p->mpoints=mpoint;
    p->mindex=index;
    p->mname=name;
    p->mgender=gender;
    p->mphone=phone;
    p->mrank=rank;
    SMStore1.push_back(p);
	return true;
}
pmemberElement memberStore::getMember(long index){
    for (long i=0;i<SMStore1.size();i++) {
        pmemberElement pme=SMStore1[i];
        if(pme->pmember!=NULL&&pme->pmember->get_member_index()==index){
            return pme;
        }
    }
    return NULL;
}

long memberStore::find_member(long index)
{
	for (long i=0;i<SMStore1.size();i++)
    {	pmemberElement pme=SMStore1[i];
		if(pme->pmember!=NULL&&pme->pmember->get_member_index()==index){
			return pme->mpoints;
		}}
	
    return NULL;
}
string memberStore::find_member_rank(long index)
{
	for (long i=0;i<SMStore1.size();i++)
    {	pmemberElement pme=SMStore1[i];
        if(pme->pmember!=NULL&&pme->pmember->get_member_index()==index){
            return pme->pmember->get_member_rank();
        }
    }
    return NULL;
}

void memberStore::member_print(long index){
	cout<<"member code"<<setw(15)<<"member name"<<setw(15)<<"member gender"<<setw(15)<<"phone number"<<setw(15)<<"member rank"<<setw(15)<<"points"<<endl;
    for (long i=0;i<SMStore1.size()-1;i++) {
        pmemberElement pme=SMStore1[i];
        if(pme->pmember!=NULL&&pme->pmember->get_member_index()==index){
            cout<<SMStore1[i]->pmember->get_member_index()<<setw(20);
            cout<<SMStore1[i]->pmember->get_member_name()<<setw(20);
            cout<<SMStore1[i]->pmember->get_member_gender()<<setw(15);
            cout<<SMStore1[i]->pmember->get_member_phone()<<setw(15);
            cout<<SMStore1[i]->pmember->get_member_rank()<<setw(15);
            cout<<SMStore1[i]->pmember->get_member_points()<<endl;
        }
    }
    
}
memberStore* prepareMember()
{
	ifstream ifile_2("/Users/dingpeien/Desktop/t_in_member.txt");
    memberStore* newMember=new memberStore();
    long code;
    string name;
    string ge;
    long ph;
	string rank;
	long double po;
	
    while (ifile_2) {
        ifile_2>>code>>name>>ge>>ph>>rank>>po;
        Member *pmember=new Member(code,name,ge,ph,rank,po);
        newMember->add_member(pmember, po,code,name,ge,ph,rank);
    }
	ifile_2.close();
    return newMember;
}
/*=================================================================================================================================*/
class shoppingCard
{public:
	long sCardCode;
	long double sCardBalance;
	
	shoppingCard(long a,long double b):sCardCode(a),sCardBalance(b){}
	~shoppingCard(){}
	
	long get_sCard_index(){return sCardCode;}
	long double get_sCard_balance(){return sCardCode;}
};
typedef struct tagscardElement
{
	shoppingCard* pscard;
	long double sbal;
	long scode;
}scardElement,*pscardelement;
/*========================================================================================================================================*/
class shoppingCardStore
{private:
	vector<pscardelement> SCStore;
public:
    shoppingCardStore(){}
    ~shoppingCardStore(){}
    long findCard(long);
    pscardelement getCard(long);
    vector<pscardelement>*getallCard(){return &SCStore;}
    bool add_card(shoppingCard*,long,long double);
};
bool shoppingCardStore::add_card(shoppingCard* pshop,long code,long double bal)
{
	pscardelement p=new scardElement;
	p->pscard=pshop;
	p->scode=code;
	p->sbal=bal;
	SCStore.push_back(p);
	return true;
}
long shoppingCardStore::findCard(long index)
{
	for (long i=0;i<SCStore.size();i++) {
		pscardelement psc=SCStore[i];
		if(psc->pscard!=NULL&&psc->pscard->get_sCard_index()==index)
        {return psc->sbal;}
	}
	return NULL;
}
pscardelement shoppingCardStore::getCard(long index)
{
	for (long i=0;i<SCStore.size();i++) {
		pscardelement psc=SCStore[i];
		if(psc->pscard!=NULL&&psc->pscard->get_sCard_index()==index)
        {//cout<<psc->scode;
            return psc;}
	}
	return NULL;
}
shoppingCardStore* prepareshoppingcard()
{
	ifstream ifile_3("/Users/dingpeien/Desktop/t_in_shop.txt");
	shoppingCardStore*newshoppingstore=new shoppingCardStore();
	long code;
	long double ba;
	while (ifile_3) {
		ifile_3>>code>>ba;
		shoppingCard*pshop=new shoppingCard(code,ba);
		newshoppingstore->add_card(pshop,code,ba);
	}
	ifile_3.close();
	return newshoppingstore;
}
/*=====================================o=================================================================================================*/
class Counter
{
    Store *aBasket;
    memberStore *aMember;
public:
    Counter(Store *pBasket);
    Counter(memberStore *pMember);
    virtual ~Counter(){}
    long double Bill();
    long double memberBill(long);
    long double Change(long double should,long double dcash);
    double get_cash();
    void memberSet();
    void memberReset();
    
};
Counter::Counter(Store *pBasket)
{
    aBasket=pBasket;
}
Counter::Counter(memberStore *pMember)
{
	aMember=pMember;
}

long double Counter::Bill()
{
    long double total=0.0;
    vector<pstoreElement>*pvse=aBasket->getAllgood();
    for (int i=0; i<(*pvse).size(); i++) {
        pstoreElement pse=(*pvse)[i];
        total+=pse->pitem->get_item_price()*pse->iNum/2;
    }
    return total;
}
long double Counter::memberBill(long index)
{
	long double total=0.0;
    vector<pstoreElement>*pvse=aBasket->getAllgood();
	aMember=prepareMember();
	string memRank=aMember->find_member_rank(index);
	if(memRank=="gold")
    {for (int i=0; i<(*pvse).size(); i++) {
        pstoreElement pse=(*pvse)[i];
		if(pse->pitem->get_item_price()<10)
            total=total+pse->pitem->get_item_price()*pse->iNum/2;
		if(pse->pitem->get_item_price()>=10&&pse->pitem->get_item_price()<20)
            total=total+(pse->pitem->get_item_price()*pse->iNum/2)*0.95;
		if(pse->pitem->get_item_price()>=20)
            total=total+(pse->pitem->get_item_price()*pse->iNum/2)*0.9;				    }
		if(total<1000){aMember->getMember(index)->mpoints+=total*1.5;}
		if(total>=1000&&total<5000)
		{aMember->getMember(index)->mpoints+=1500+(total-1000)*1.8;}
		if(total>=5000){aMember->getMember(index)->mpoints+=8700+(total-5000)*2;}
    }
	if(memRank=="silver")
    {for (int i=0; i<(*pvse).size(); i++) {
        pstoreElement pse=(*pvse)[i];
        total+=pse->pitem->get_item_price()*pse->iNum/2;
    }
		if(total<1000) total*=0.9;
		else if(total>=1000&&total<2000) total=950+(total-1000)*0.9;
		else if(total>=2000) total=1850+(total-2000)*0.85;
		if(total<2000){aMember->getMember(index)->mpoints+=total*1.2;}
		if(total>2000&&total<5000)
		{aMember->getMember(index)->mpoints+=2400+(total-2000)*1.5;}
		if(total>=5000){aMember->getMember(index)->mpoints+=6900+(total-5000)*1.8;}
		if(aMember->getMember(index)->mpoints>=50000){aMember->getMember(index)->mrank="gold";}
    }
	if(memRank=="general")
    { for (int i=0; i<(*pvse).size(); i++) {
        pstoreElement pse=(*pvse)[i];
        total+=pse->pitem->get_item_price()*pse->iNum/2;
    }
        if(total>=2000&&total<5000) total=2000+(total-2000)*0.95;
        if(total>=5000) total=5000+(total-5000)*0.9;
        aMember->getMember(index)->mpoints+=total*0.5;
        if(aMember->getMember(index)->mpoints>=10000&&aMember->getMember(index)->mpoints<50000){aMember->getMember(index)->mrank="silver";}
        if(aMember->getMember(index)->mpoints>=50000){aMember->getMember(index)->mrank="gold";}
    }
	return total;
}

long double Counter::Change(long double sh_pay, long double cash)
{
	ofstream ofile_2("/Users/dingpeien/Desktop/t_out.txt",ios::app);
    long double check=0.0;
    if(cash>=sh_pay){
        check=cash-sh_pay;
        ofile_2<<"PAYMENT TYPE : CASH , AMOUNT "<<' '<<cash<<endl;
        cout<<"PAYMENT TYPE : CASH , AMOUNT "<<' '<<cash<<endl;
        ofile_2<<"Give change : "<<' '<<check<<"RMB"<<endl;
        cout<<"Give change : "<<' '<<check<<"RMB"<<endl;
        return -check;}
    else{check=sh_pay-cash;cout<<"you also need to pay another :" <<check<<" RMB"<<endl;
        cout<<"PAYMENT TYPE : CASH , AMOUNT :  "<<' '<<cash<<endl;
        ofile_2<<"PAYMENT TYPE : CASH , AMOUNT :  "<<' '<<cash<<endl;return check;}
    ofile_2.close();
}
void Counter::memberReset()
{
	ofstream ofile_3("/Users/dingpeien/Desktop/member_OUT.txt",ios::trunc);
    aMember=prepareMember();
    vector<pmemberElement>*pme=aMember->getallMember();
    for (long i=0; i<(*pme).size()-1; i++) {
        pmemberElement pe=(*pme)[i];
        ofile_3<<pe->mindex<<' '<<pe->mname<<' '<<pe->mgender<<' '<<pe->mphone<<' '<<pe->mrank<<' '<<pe->mpoints<<endl;
    }}
void Counter::memberSet()
{
	ofstream ofile_3("/Users/dingpeien/Desktop/t_in_member.txt",ios::trunc);
    aMember=prepareMember();
    vector<pmemberElement>*pme=aMember->getallMember();
    for (long i=0; i<(*pme).size()-1; i++) {
        pmemberElement pe=(*pme)[i];
        ofile_3<<pe->mindex<<' '<<pe->mname<<' '<<pe->mgender<<' '<<pe->mphone<<' '<<pe->mrank<<' '<<pe->mpoints<<endl;
    }}
/*===================================================================================================*/
class payment
{public:
	shoppingCardStore* ashopcard;
	payment(){}
	payment(shoppingCardStore*);
    virtual ~payment(){}
    long double shopcardPay(long double,long double,long);
	void shopcardReset();
	void shopcardSet();
	void memberReset();
	void memberSet();
};
payment::payment(shoppingCardStore*pshop)
{
	ashopcard=pshop;
}
long double payment::shopcardPay(long double bal,long double you_pay,long index)
{
	ofstream ofile_2("/Users/dingpeien/Desktop/t_out.txt",ios::app);
	ashopcard=prepareshoppingcard();
	long double bal_ex=ashopcard->findCard(index);
	long double bal_now;
	if(you_pay<=bal_ex){
		bal_now=bal-you_pay;
	    ashopcard->getCard(index)->sbal-=you_pay;	ofile_2<<"PAYMENT TYPE : SHOPPING CARD "<<endl;
	    ofile_2<<"SHOPPING CARD NUMBER:"<<index<<"AMOUNT "<<' '<<you_pay<<"RMB"<<endl;
        cout<<"SHOPPING CARD NUMBER:"<<index<<"AMOUNT "<<' '<<you_pay<<"RMB"<<endl;
        cout<<"you should pay another "<<bal_now<<' '<<"RMB"<<endl;
    }
	else {
        cout<<"sorry,the balance in your shopping card is less than "<<you_pay<<endl;
        cout<<"your card can only pay "<<bal_ex<<"RMB"<<endl;
        cout<<"please chose another payment type~"<<endl;
        ashopcard->getCard(index)->pscard->sCardBalance=0;
        bal_now=bal-bal_ex;
        ofile_2<<"PAYMENT TYPE : SHOPPING CARD"<<endl;
        ofile_2<<"SHOPPING CARD NUMBER :"<<index<<"    AMOUNT : "<<' '<<bal_ex<<"RMB"<<endl;
        cout<<"SHOPPING CARD NUMBER :"<<index<<"    AMOUNT : "<<' '<<bal_ex<<"RMB"<<endl;
        cout<<"so you also need to pay another : "<<bal_now<<"RMB"<<endl;
	}
	ofile_2.close();
	return bal_now;
}
void payment::shopcardReset()
{
	
	ofstream ofile_3("/Users/dingpeien/Desktop/shop_out.txt",ios::app);
    ashopcard=prepareshoppingcard();
    vector<pscardelement>*pse=ashopcard->getallCard();
    for (long i=0; i<(*pse).size()-1; i++) {
        pscardelement pe=(*pse)[i];
        ofile_3<<pe->scode<<' '<<pe->sbal<<endl;
	}
    
}
void payment::shopcardSet()
{
	
	ofstream ofile_3("/Users/dingpeien/Desktop/t_in_shop.txt");
    ashopcard=prepareshoppingcard();
    vector<pscardelement>*pse=ashopcard->getallCard();
    for (long i=0; i<(*pse).size()-1; i++) {
        pscardelement pe=(*pse)[i];
        ofile_3<<pe->scode<<' '<<pe->sbal<<endl;
	}
    
}
long double bankPay(long double bal,long double you_pay,string name,long number)
{
	ofstream ofile_2("/Users/dingpeien/Desktop/t_out.txt",ios::app);
	long double shpay;
	shpay=bal-you_pay;
	if(shpay>0){cout<<"you also need to pay another : "<<shpay<<"RMB"<<endl;}
	ofile_2<<"PAYMENT TYPE : BANK CARD "<<endl;
	ofile_2<<"NAME : "<<name<<' '<<"  CARD NUMBER "<<number<<"   AMOUNT : "<<' '<<you_pay<<endl;
    cout<<"NAME : "<<name<<' '<<"  CARD NUMBER "<<number<<"   AMOUNT : "<<' '<<you_pay<<endl;
	ofile_2.close();
	return shpay;
}
/*===================================================================================================*/
void remind()
{
    cout<<endl;
    cout<<"welcome to the supermarket"<<endl;
    cout<<"please input the data as hint"<<endl;
    cout<<"please input -1 to finish settlement"<<endl;
    cout<<endl;
    cout<<endl;
}
int main(int argc, char *argv[]) {
	Store *newStore;
	newStore=prepareStore();
	
	memberStore* newMember;
  	newMember=prepareMember();
	
	shoppingCardStore* newshopcard;
	newshopcard=prepareshoppingcard();
    
    Store *pBasket=new Store();
    Counter Counter(pBasket);
	payment Payment;
    Item *pMyGood;
    cout<<"Are you a member of us ? YES:1 NO:0"<<endl;
	int a;
	long mem_index = 0;
	cin>>a;
	if (a==1) {
		cout<<"please input your member code"<<endl;
		cin>>mem_index;
        newMember->member_print(mem_index);
		
	}
    cout<<"enter the settlement mode"<<endl;
	
    remind();
    long number;
    long iidex=0;
    while (iidex!=-1) {
        cout<<"please input the code of the good and the quantity of good you want"<<endl;
        cin>>iidex;
        pstoreElement pse=newStore->getGood(iidex);
        if (pse==NULL&&iidex!=-1) {
            cout<<"sorry,we do not have such good with input code"<<iidex<<endl;
            continue;
        }
        number=cin.get();
        if(number=='\n'){number=1;}
        else cin>>number;
        if (number<0) {
            cout<<"input the wrong number,the number should > 0"<<endl;
            continue;
        }
        long tnumber=newStore->findGood(iidex);
        if (tnumber<=0) {
            cout<<"over"<<endl;
        }
        else{
            if (number>tnumber) {
                cout<<"sorry,our supermarket has goods"<<pse->pitem->get_item_name()<<"only"<<tnumber<<"please buy the quantities "<<tnumber<<"just now"<<endl;
                pMyGood=pse->pitem->clone();
                pBasket->add_good(pMyGood, tnumber);
                pse->iNum=0;
            }
            else
            {
                cout<<"you have bought"<<' '<<number<<' '<<pse->pitem->get_item_name()<<endl;
                pMyGood=pse->pitem->clone();
                pBasket->add_good(pMyGood, number);
                pse->iNum=tnumber-number;
            }
        }
    }
	
   	cout<<"all goods cost "<<endl;
	cout<<"total"<<' '<<Counter.Bill()<<"RMB"<<endl;
	long double totalPay=Counter.Bill();
    if(a==1) {
		cout<<"To give you a discount because you are a member,you should pay"<<endl;
	    cout<<"total :"<<' '<<Counter.memberBill(mem_index)<<"RMB"<<endl;
	    totalPay=Counter.memberBill(mem_index);
    }
	cout<<endl;
	cout<<"Enter the payment mode"<<endl;
	cout<<"please chose the type of payment"<<endl;
	cout<<"WARM PROMPT : YOU CAN CHOSE VARIOUS TYPIES OF PAYMENT WHILE PAYING"<<endl;
	int pay_dex=0;
	do{
		cout<<"CASH : 1  ;  BANK CARD : 2 ; SHOPPING CARD : 3"<<endl;
		cin>>pay_dex;
        
		if(pay_dex==1) {cout<<"please input the total cash "<<endl;
            long double CASH_1=0;
            cin>>CASH_1;
            totalPay=Counter.Change(totalPay,CASH_1);
            
        }
		if(pay_dex==2){cout<<"please input the bank card number, name, money amount"<<endl;
            long double CASH_2; string NAME; long NUM;
            cin>>NUM>>NAME>>CASH_2;
            totalPay=bankPay(totalPay,CASH_2,NAME,NUM);}
        
		if(pay_dex==3){cout<<"please input the shopping card number, money amount"<<endl;
			long double CASH_3;long NUMBER;
			cin>>NUMBER>>CASH_3;
			totalPay=Payment.shopcardPay(totalPay,CASH_3,NUMBER);
        }
    }while (totalPay>0);
	cout<<endl;
	cout<<"DATA UPDATE     Overwrite the original file : 1  Write in the new file : 2 "<<endl;
	int reset;
	cin>>reset;
	if(reset==1){Payment.shopcardSet();Counter.memberSet();}
	else if(reset==2)
	{Payment.shopcardReset();Counter.memberReset();}
    pBasket->basket_print();
	delete newStore;
	delete newMember;
	delete newshopcard;
	delete pBasket;
	cout<<"THANKS"<<endl;
    return 0;	
}