#include<iostream>//for cin/cout/ others
#include<cstdlib>//for using rand function
#include<vector>//for using vector
#include<ctime>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairWiseProduct(const vector<int>& numbers)//vector pass by reference
{
    long long result=0;
    int n=numbers.size();//Determine vector size.
//Go for all possible value
    for(int i=0;i<n;++i)
    {
        //for(long long j=0/i;j<n;j++) is wrong as compare i and after i;
        for(int j=i+1;j<n;++j)
        {
            if((long long)numbers[i]*numbers[j]>result)//type casting is necessary for multiplication
            {
                result=(long long)numbers[i]*numbers[j];
            }
        }
    }
    return result;
}

long long MaxPairWiseProductFAST(const vector<int>& numbers)
{
    int n=numbers.size();

    int max_index1=-1;
    for(int i=0;i<n;++i)
        if((numbers[i]>numbers[max_index1])||(max_index1==-1))
            max_index1=i;

    int max_index2=-1;
    for(int j=0;j<n;++j)
        //if((numbers[j]!=numbers[max_index1])&&(max_index2==-1)||(numbers[j]>numbers[max_index2]))
        if( (j!=max_index1)&&( (max_index2==-1)||(numbers[j]>numbers[max_index2]) ) )
            max_index2=j;

    //if((numbers[j]]!=numbers[max_index1])&&(max_index2==-1)||(numbers[j]>numbers[max_index2]))
    //is wrong as 4 5 9 8 9, output should be 9*9;but it will show 9*8
    //which is wrong if 2 or more max numbers(9=9,9 is 2 times here) are there;
    //so instead of value use index

    return ((long long)numbers[max_index1]*numbers[max_index2]);
}



/*
int main(){
    ///...........STRESS TEST to DEBUG a program................
    srand(time(0));
    while(true)
    {
        int n;
        n=rand()%100+2;//atleat 2 elements needed for pair
        vector<int>numbers(n);
        for(int i=0;i<n;++i)
        {
            numbers[i]=rand()%1000+1;
            cout<<numbers[i]<<" ";
        }
        cout<<std::endl;
        long long result_1=MaxPairWiseProduct(numbers);
        long long result_2=MaxPairWiseProductFAST(numbers);

        cout<<result_1<<' '<<result_2<<" ";
        if(result_1!=result_2)
        {
            cout<<" .........Error...........\n";
            break;
        }
        cout<<" ok"<<std::endl;

    }
    //long long result=MaxPairWiseProduct(vector<int>(1000,5));
    //pass a vector size 1000 and each element is 5;
    //cout<<result<<"\n";

}*/
    //.......................



int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    //std::cout<<MaxPairwiseProduct(numbers)<< "\n";
    std::cout<<MaxPairWiseProductFAST(numbers)<< "\n";
    return 0;
}

