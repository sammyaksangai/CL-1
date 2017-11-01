#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
int num;
class Point 
{
    public:
    float x,y;
    void set(float a, float b)
    {
        x = a;
        y = b;
    }
    float getX()
        {return x;}
    float getY()
        {return y;}
};

class kmeans
{
    
    public:
    Point p[100];
    Point c[10];
    int n;
    
    float min_arr[101];
    
    
    void initialize()
    {
        cout<<"Enter number of points"<<endl;
        cin>>n;
        for(int i=0;i<n;i++)
        {   
            int x,y;
            cout<<"Enter point"<<endl;
            cin>>x>>y;
            p[i].set(x,y);
        }
        cout<<"Enter the number of clusters"<<endl;
        cin>>num;
        for(int j=0;j<num;j++)
        {
            int c_n = rand()%n;
            c[j].set(p[c_n].getX(),p[c_n].getY());
        }
        
     }
     
    /*void initialize_array(int ini[][])
    {
        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++)
                ini[i][j] = 0;
    }*/
     
     void display_initial()
     {
        for(int i=0;i<num;i++)
        {
            cout<<"Centroid of cluster number "<<i+1<<" is "<<c[i].getX()<<" , "<<c[i].getY()<<endl;
        }
        
     }
     
     float euclidean_dist(float a,float b, float c, float d)
       {
            float e = abs(a-c);
            float f = abs(b-d);
            e = e*e;
            f=f*f;
            return (sqrt(e+f));
        }
        
        
     void calculate_cluster()
     {
        float dist[num][n];
        
        
        for (int i=0;i<n;i++)
        {
            int x = p[i].getX();
            int y = p[i].getY();
            int min,min_index;
            for(int j=0;j<num;j++)
            {
                float a=c[j].getX();
                float b=c[j].getY();
               /* cout<<endl;
                cout<<a<<" "<<b<<endl;
                cout<<endl;*/
                dist[j][i] = euclidean_dist(a,b,x,y);
                if(j==0)
                {
                    min = dist[j][i];
                    min_index = j;
                }
                else if(j!=0 && dist[j][i] <= dist[j-1][i])
                {
                    min = dist[j][i];
                    min_index = j;
                }             
            }
            cout<<"The given point "<<p[i].getX()<<","<<p[i].getY()<<" belongs to cluster "<<min_index+1<<endl;
            min_arr[i] = min_index+1;
         }
     }
      
    void recluster()
    {   
        float arrX[100][100];
        float arrY[100][100];
        int count[num]; 
        /*intialize_array(arrX);
        intialize_array(arrY);*/
        for(int l=0;l<n;l++)
        {
            int val = min_arr[l];
            count[val]++;
            arrX[val][l] = p[l].getX();
            arrY[val][l] = p[l].getY();
        }
        for(int i=1;i<=num;i++)
        {
        
            float sum1 = 0;
            float sum2 = 0;
            for(int j=0;j<n;j++)
            { 
                sum1 += arrX[i][j];
                sum2 += arrY[i][j];
            }
            sum1 /= count[i];
            sum2 /= count[i];
            cout<<sum1<<" "<<sum2;
            c[i-1].set(sum1,sum2);
            //cout<<setprecision(2);
            cout<<"Centroid of cluster number "<<i<<" is "<<c[i-1].getX()<<" , "<<c[i-1].getY()<<endl;
            
        }   
    }
    
    
     
};
            
int main()
{
    kmeans k;
    k.initialize();
    k.display_initial();
    for (int h=0;h<num;h++)
    {
        k.calculate_cluster();
        k.recluster();
    }
    k.calculate_cluster();
    return 0;
}
                
                
            
        
        
     
            
      
        
        
