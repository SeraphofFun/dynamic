#include <iostream>
using namespace std;
bool yoxlama(int* length) {
    if (*length <= 0) {
        return false;
    }
    return true;
}
int* ayiran(int length){
    int* temp =new int[length];
    
    temp = nullptr;
    return temp;
}
int* dolduran( int* length) {
    srand(time(NULL));
    int* ptr = new int[*length];
    int min = 0;
    int max = 10;
    for (int i = 0; i < *length; i++)
    {
        ptr[i] = rand() % max;
    }
    return ptr;
}
void ekranacixaran(int* ptr, int* length) {
    cout << endl;
    for (int i = 0; i < *length; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;
}
void silen(int* ptr) {
    delete[] ptr;
    ptr = nullptr;
}
int* append(int* ptr, int* length, int newelement) {
    int* temp = new int[*length + 1];
    for (int i = 0; i < *length + 1; i++)
    {
        if (i == *length)
            temp[i] = newelement;
        else
            temp[i] =  ptr[i];
    }
    delete[] ptr;
    ptr = temp;
    temp = nullptr;
    (*length)++;
    return ptr;
}
int* appendindex(int* ptr, int* length, int newelement,int l) {
    int* temp = new int[*length + 1];
    int i2 =0;
    for (int i = 0; i < *length + 1; i++)
    {
        if (i == l)
            temp[i] = newelement;

        else {
            temp[i] = ptr[i2];
            i2++;
        }
    }
    delete[] ptr;
    ptr = temp;
    temp = nullptr;
    (*length)++;
    return ptr;
}
int* appendblock(int* ptr,int* ptr2, int* length,int* length2) {
    int* temp = new int[*length + *length2];
    for (int i = 0; i < *length; i++)
    {
            temp[i] = ptr[i];
    }
    for (int i = *length,j=0; i <  *length2+ *length; i++,j++)
    {
        temp[i] = ptr2[j];
    }
    delete[] ptr;
    ptr = temp;
    temp = nullptr;
    (*length) += *length2;
    return ptr;
}
int* appendblockindex(int* ptr, int* ptr2, int* length, int* length2,int index) {
    int* temp = new int[*length + *length2];
    for (int s = 0, i =0,j=0; s < *length + *length2; s++)
    {


        if (s == index) {
            temp[s] = ptr2[i];
            i++;
            if (i<*length2)
            {
                index++;
            }
        }
        else {
            temp[s] = ptr[j];
            j++;
        }
        
    }
    delete[] ptr;
    ptr = temp;
    temp = nullptr;
    (*length) += *length2;
    return ptr;
}
int* removeblockindex(int* ptr, int* ptr2, int* length, int* length2, int index) {
    int* temp = new int[*length - *length2];
    for (int s = 0, i = 0, j = 0; s < *length; s++)
    {


        if (s == index) {
            if (i < *length2-1)
            {
                index++;
            }
            i++;
        }
        else {
            temp[j] = ptr[s];
            j++;
        }

    }
    delete[] ptr;
    ptr = temp;
    temp = nullptr;
    (*length) -= *length2;
    return ptr;
}


int* appendindexsilen(int* ptr, int* length, int l) {
    int* temp = new int[*length - 1];
    int i2 = 0;
    for (int i = 0; i < *length; i++)
    {
        if (i == l)
            continue;
        else {
            temp[i] = ptr[i2];
            i2++;
        }

    }
    delete[] ptr;
    ptr = temp;
    temp = nullptr;
    (*length)--;
    return ptr;
}
int main()
{
    
    int a;
    cin >> a;
    int* l = new int(a);
    int* l2 = new int(a+2);

    int* ptr = ayiran(a);
    ptr = dolduran(l);
    ekranacixaran(ptr, l);
   /* silen(ptr);
    ekranacixaran(ptr, l);
    int newe;
    cin >> newe;
    ptr = dolduran(l);
    ptr = append(ptr, l, newe);
    ekranacixaran(ptr, l);
    silen(ptr);
    ptr = dolduran(l);
    cout << endl << "yenielement" << endl;
    cin >> newe;
    cout << endl << "index" << endl;

    int ind;
    cin >> ind;

    ptr = appendindex(ptr, l, newe,ind);
    ekranacixaran(ptr, l);
    
    cout << endl << "index" << endl;
    cin >> ind;
    ptr = appendindexsilen(ptr, l, ind);
    ekranacixaran(ptr, l);*/


    int* ptr2 = ayiran(a+2);
    ptr2 = dolduran(l2);
    ekranacixaran(ptr2, l2);
    /*ptr = appendblock(ptr, ptr2, l, l2);
    ekranacixaran(ptr, l);*/
    int o;
    cin >> o;
    ptr = appendblockindex(ptr, ptr2, l, l2,o);
    ekranacixaran(ptr, l);
    ptr = removeblockindex(ptr, ptr2, l, l2, o);
    ekranacixaran(ptr, l);
}

