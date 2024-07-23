#include <iostream>
#include <algorithm>
#include <string>
#include <random>
#include <iterator>
#include <ctime>
#include <Windows.h>
#define clear system("clear||@cls");
using namespace std;
/*
unsigned int
float
Выполнить зеркальную перестановку в группе рядом стоящих разрядов,
количество которых и номер младшего разряда в группе задаются с клавиатуры.
0000 0000 0000 0000 0000 0000 0000 1010
0100 0000 1011 0000 0000 0000 0000 0000
3253
*/

void bin_unsigned(unsigned int a){
    int i = 0, bit = 0;
    /* Вывод переменной unsigned int в виде двоичного кода */
    for(i=sizeof(a)*8-1;i>=0;i--)
    {
        if (i%4==3 && i!=31) cout<<" ";
        bit = (a & (1<<(i)));
        if(bit == 0)
        {
        	cout<<'0';
        }
        else
        {
        	cout<<'1';
        }
    }
    cout<< endl;
}

unsigned int make_mask(int count_bit, int least_bit){
    unsigned int m1;
    int i, least = least_bit, count = count_bit;

    /* Создаём маску на 32 бита только из единиц и возвращаем её */
    for(i=sizeof(m1)*8-1;i>=0;i--)
    {
        if ((least + count - 1 >= i)&&(i >= least)){
            m1 = ((m1<<1)+1);
        }
        else{
            m1 = m1<<1;
        }
    }
    return m1;
}

void change(unsigned int a, int count_bit, int least_bit, int F_or_I){
    int count = count_bit, least = least_bit, count2, i;
    unsigned int mask1 = 0, original = a, original2, mask_left, mask_right, mask_null, mask_temp1, mask_temp2;
    float fl_new;

    /* Сколько символов надо зеркалить */
    count2 = count / 2;
    cout<<"Original:"<<endl;
    bin_unsigned(original);

    /* Маска из единиц для доставания нужных битов */
    mask1 = make_mask(count2,least);
    mask1 = mask1 | make_mask(count2,least + count2 + (count%2));

    /* Маска для удаления битов которые зеркаляться и копия оригинала */
    mask_null = ~mask1;
    original2 = original;

    /* Вытаскиваем нужные биты */
    original2 = original2 & mask1;

    /* Маски для разделения на левую и правую стороны */
    mask_left = make_mask(count2, least + count2 + (count%2));
    mask_right = make_mask(count2,least);

    /* Вытаскиваем левую и правую стороны, готовим временные переменные, где будем зеркалить каждую сторону */
    mask_left = original2 & mask_left;
    mask_right = original2 & mask_right;
    mask_temp1 = 0;
    mask_temp2 = 0;

    /* Сдвигаем в правый край биты, просматриваем первый и ставим его на новое место с другой стороны во временной переменной, повторяем столько, сколько бит с каждой стороны */
    for(i = 0; i <= count2; i++){
        mask_temp1 |= ((mask_right>>(i+least))&1)<<(count2-1-i);
        mask_temp2 |= ((mask_left>>(i+least+count2))&1)<<(count-1-i);
    }

    /* Возвращаем уже зеркаленные биты обратно в маски право/лево */
    mask_right = mask_temp1;
    mask_left = mask_temp2;

    /* Смотря в каком месте оказалась левая сторона - сдвигаем её левее или правее (теперь самый правый бит имеет номер least, а самый левый стоит на месте least+count2 */
    if((count2-least)>0){
        mask_left = mask_left >> (count2 - least);
    }
    else{
        mask_left = mask_left << (least - count2 - (count%2));
    }

    /* Правую сторону надо менять с левой местами - сдвигаем её всегда левее */
    mask_right = mask_right << (count2 + least + (count%2));

    /* Вместо вырезанных бит вставляем обработанные (поменяли левую и правую сторону + отзеркалили их) */
    original = (original & mask_null) | mask_left | mask_right;

    cout<<"New:"<<endl;
    bin_unsigned(original);
    if(F_or_I == 0){
        cout<<"New unsigned int: "<<original<<endl;
    }
    else{
        fl_new = *((float*)&original);
        cout<<"New float: "<<fl_new<<endl;
    }
}

int main(){
    unsigned int a = 0, b_int = 0;
    int count_bit, least_bit, work=10, flag_error = 0;
    float b = 0;


    while(work!=0){
        clear;
        if((a!=0)||(b!=0)){
            cout << "Unsigned int = " << a << endl <<"Float = " << b << endl;
            cout << "Unsigned int = ";
            bin_unsigned(a);
            cout << "Float = ";
            bin_unsigned(b_int);
        }
        cout<<"1. Enter unsigned int and float"<<endl;
        cout<<"2. Transform only unsigned int"<<endl;
        cout<<"3. Transform only float"<<endl;
        cout<<"4. Transform unsigned int and float"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"\nAnswer: ";
        cin>>work;

        flag_error = 0;

        if(work == 1){
            cout<<"Enter unsigned int(>0 and !=0): ";
            cin>>a;
            cout<<"Enter float(!=0): ";
            cin>>b;
            if((a <= 0) || (b == 0)){
                flag_error = 1;
                a = 0;
                b = 0;
                cout<<"Not correct numbers"<<endl;
            }
        }

        if((work == 2) || (work == 3) || (work == 4)){
            if((work == 2) && (a == 0)){
                flag_error = 1;
                cout<<"You didn't set unsigned int"<<endl;
            }
            if((work == 3) && (b_int == 0)){
                flag_error = 1;
                cout<<"You didn't set float"<<endl;
            }
            if((work == 4) && ((a == 0) || (b_int == 0))){
                flag_error = 1;
                cout<<"You didn't set unsigned int or float"<<endl;
            }

            if(flag_error == 0){
                cout<<"Enter count of bits (>1): ";
                cin>>count_bit;
                cout<<"Enter least bit: ";
                cin>>least_bit;
            }

            if(((least_bit < 0) || (least_bit >= 31)) && flag_error == 0){
                flag_error = 1;
                cout<<"Not correct least bit"<<endl;
            }
            if(((count_bit <= 1) || ((least_bit + count_bit) > 32))&& flag_error == 0){
                flag_error = 1;
                cout<<"Not correct count of bits"<<endl;
            }
        }

        if(flag_error == 1){
            work = 10;
        }

        switch(work){
            case 1:
                b_int = *((unsigned int*)&b);

                work = 10;
                break;

            case 2:
                cout<<"\nAnswer unsigned int:"<<endl;
                change(a, count_bit, least_bit, 0);

                work = 10;
                system("pause");
                break;

            case 3:
                cout<<"\nAnswer float:"<<endl;
                change(b_int, count_bit, least_bit, 1);

                work = 10;
                system("pause");
                break;

            case 4:
                cout<<"\nAnswer unsigned int:"<<endl;
                change(a, count_bit, least_bit, 0);
                cout<<"\nAnswer float:"<<endl;
                change(b_int, count_bit, least_bit, 1);

                work = 10;
                system("pause");
                break;

            case 0:
                clear;
                cout<<"Thanks for using"<<endl<<endl;
                work = 0;
                break;

            default:
                cout<<"Not correct"<<endl;
                work = 10;
                system("pause");
        }
    }
    return 0;
}

