#include<iostream>
#include<cstdlib>

#define WHITE 0
#define BLACK 1

using namespace std;

void create_nodes(int nodes, int** &edges, int* &parents, int* &colors){

    edges=new int*[nodes];
    parents=new int[nodes];
    colors=new int[nodes];

    }

void populate_nodes(int nodes, int** &edges, int* &parents, int* &colors, int high, int low){

    for(int i=0; i<nodes; i++){
        edges[i]=new int[nodes];
        for(int j=0; j<nodes; j++){
            if(i!=j){
                edges[i][j]=low+rand()%(high-low+1);
                parents[i]=i;
                colors[i]= WHITE;

            }

            else{
                edges[i][j]=0;

            }

        }
    }


    }

void display_graph(int nodes, int** edges){

    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            cout<<edges[i][j]<<" ";
        }
        cout<<endl;
    }

    }

bool find_back_edge(int nodes, int* colors,int *parent, int i){

    int *indexArray; //array of all nodes/iterators
    int next; //parent of the current node


    indexArray=new int[nodes];

    for(int j=indexArray[i]; j<indexArray[nodes]; j++){

        int next=parent[j]; //adjacent or parent of ith node


        if(colors[next]==BLACK){ //if parent node is already visited, cycle is found
            return true;
        }
        if(colors[next]==WHITE && find_back_edge(nodes,colors,parent,next)){
            return true; //if parent node is not explored, we recur to the parent->parent
        }                //until we reach source to look for cycles

        colors[j]==BLACK; //after searching mark as visited
    }

    return false;

    }

bool check_cycle(int nodes, int** edges, int* parents, int* colors){

    for(int i=0; i<nodes; i++){

        if(colors[i]==WHITE){
            if(find_back_edge(nodes,colors,parents,i)==true){
                return true;
            }
        }
        else{
            return false;
        }

    }

    }

int main(){

    int nodes;
    int high,low;

    cout<<"Enter number of nodes: ";
    cin>>nodes;
    cout<<"Enter range high, low: ";
    cin>>high>>low;
    cout<<endl;

    int **edges;
    int *parents;
    int *colors;

    create_nodes(nodes,edges,parents,colors);
    populate_nodes(nodes,edges,parents,colors,high,low);
    display_graph(nodes,edges);

    //check_cycle(nodes,edges,parents,colors);

    if(check_cycle(nodes,edges,parents,colors)==true){
        cout<<"There is a cycle"<<endl;
    }
    else{
        cout<<"No cycle"<<endl;
    }

   return 0;

   //n=number of nodes
   //Time Complexity = (n^2)+(n^2)+n+n
   //                = 2(n^2+n)
}
