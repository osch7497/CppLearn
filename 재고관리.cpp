#include <iostream>
#include <map>
#include <string>
using namespace std;
class Product{
    string info;
    bool rePurchase;
    int nowCountProduct;
public:
    Product(string s,bool b,int i):info(s),rePurchase(b),nowCountProduct(i){}
    void display(){
        printf("%s\n",info.c_str());
        printf("재구매 여부:%c\n",rePurchase?'O':'X');
        printf("현재 재고량:%d\n",nowCountProduct);
    }
    void setCount(int c){nowCountProduct=c;}
    void setRePurchase(bool b){rePurchase=b;}
    void setInfo(string s){info=s;}
};
map<int,Product*> products;
map<int,Product*>::iterator it;
void add_product(){
    int k;
    printf("부품 번호를 입력하세요(5자리)\n");
    scanf("%d",&k);
    system("cls");

    string i;
    printf("설명을 입력하세요(10자 이내)\n");
    cin>>i;
    system("cls");

    int in;
    printf("현재 재고량을 입력하세요\n");
    scanf("%c",&in);
    system("cls");

    char c = 'N';
    while(c != 'T'&&c != 'F'){
    printf("재구매 여부를 입력하세요(T/F)\n");
    scanf("%c",&c);system("cls");
    }

    bool bools;
    bools = ((c=='T')?true:false);
    Product* t = new Product(i,bools,in);
    products[k] = t;
}
void manage_Product(){
    int ans;
    while(1){
        printf("<재고관리 프로그램>\n");
        printf("1.새 부품 추가\n");
        printf("2.부품 검색\n");
        printf("3.기존 부품의 재고 변경\n");
        printf("4.기존 부품의 재구매 여부 변경\n");
        printf("5.기존 부품의 설명을 변경\n");
        printf("6.종료\n");
        printf("실행할 명령의 번호:");
        scanf("%d",&ans);
        switch(ans){
            case(1):
                break;
            case(2):
                break;
            case(3):
                break;
            case(4):
                break;
            case(5):
                break;
            case(6):
                return;
        }
        system("cls");
    }
}
int main()
{
        manage_Product();
}
