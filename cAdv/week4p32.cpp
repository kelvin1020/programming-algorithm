#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) 
{
    int n;
    char a[5000];
    char word[80];
    int numLine=0;
    int numWord=0;
    int numWord2=0;
    int numSpace=0;
    int wordnumber=0;

//bool flag=0;
    cin>>n;
    cin.get();
    cin.getline(a,5000);
//cout<<a<<endl;
    int i=0;
//int j=0;
    while (a[i]!='\0')
    {
        for (int j=0;a[i+j]==' ';j++)
        {
            numSpace++;
        }
        i=i+numSpace;
        numSpace=0;
        for (int j=0; a[i+j]!=' ' && a[i+j]!='\0';j++)
        {
            word[j]=a[i+j];
            //cout<<word[j]<<" ";
            numWord++;
        }
        i=i+numWord;
        //cout<<i<<endl;

        wordnumber++;
        for (int j=0;a[i+j]==' ';j++)
        {
            numSpace++;
        }

        i=i+numSpace;
        numSpace=0;
        //cout<<i<<endl;
        word[numWord]='\0';

        if (numLine+numWord==80)
        {
            cout<<word;
            cout<<endl;
            numLine=0;
            numWord=0;
        }

        else if (numLine+numWord>80 && wordnumber<n)
        {
            cout<<endl;
            cout<<word;
            cout<<" ";
            numLine=numWord+1;
            numWord=0;
        }

        else if (numLine+numWord<80 && wordnumber==n)
        {
            cout<<word<<endl;
        }

        else if (numLine+numWord<80 && wordnumber<n)
        {
            for(int j=0;a[i+j]!=' ' && a[i+j]!='\0';j++)
            {
            numWord2++;
            }

//cout<<numWord2<<endl;

            if (numLine+numWord+numWord2+1>80)
            {
                cout<<word<<endl;
                numLine=0;
                numWord=0;
                numWord2=0;
            }
            else 
            {
                cout<<word<<" ";
                numLine=numLine+numWord+1;
                numWord=0;
                numWord2=0;
            }
        }

    }

    return 0;
}