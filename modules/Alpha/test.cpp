#include <iostream>
#include <fstream>
using namespace std;
int reverseInt(int i) {
    unsigned char c1, c2, c3, c4;
    c1 = i & 255;
    c2 = (i >> 8) & 255;
    c3 = (i >> 16) & 255;
    c4 = (i >> 24) & 255;
    return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
}

int main(){
    unsigned int data[28][28];
    ifstream file("./data/mnist/train-images-idx3-ubyte",ios::binary);
    int magic_number=0;
    int number_images=0;
    int rows=0;
    int cols=0;
    unsigned char temp;
    file.read((char*)&magic_number, sizeof(magic_number));
    magic_number=reverseInt(magic_number);
    cout<<magic_number<<endl;
    file.read((char*)&number_images, sizeof(number_images));
    number_images=reverseInt(number_images);
    file.read((char*)&rows,sizeof(int));
    rows=reverseInt(rows);
    file.read((char*)&cols, sizeof(int));
    cols=reverseInt(cols);
    cout<<number_images<<" "<<rows<<" "<<cols<<endl;
    for(int i=0; i<28; i++)
    {
        for(int j=0; j<28; j++){
                file.read((char*)&temp,sizeof(temp));
                data[i][j]=(int)temp;
                cout<<(int)temp<<" ";
            }
            cout<<endl;
        }
        
        return 0;
    }
