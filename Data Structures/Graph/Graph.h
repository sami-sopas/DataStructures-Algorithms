#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include"NodeEdge.h"
#include"NodeVertex.h"
#include<iostream>
#include<fstream>
#include<sstream>

class Graph
{
    private:
        NodeVertex* anchor; //Header del grafo, el cual es el header de la lista de vertices

    public:
        Graph();
        //Graph(const Graph&);

        //Operaciones del grafo
        bool isEmpty(void) const; //return true when graph is empty (no list of vertex)

        NodeVertex* findVertex(const Place&) const; //return a specific vertex its name

        NodeVertex* getPrevVertex(NodeVertex*) const; //return the previuos node

        void insertVertex(const Place&);

                //        origin       destiny             weight
        void insertEdge(const Place&,const Place&,const std::string&); //insert edge between 2 vertexs

        void displayGraph(void); //display in the screen all the graph(vertexes and eges)

        void displayVertexes(void); //display all the vertexes

        void deleteVertex(const Place&); //Delete a vertex (main list)

            //             origin       destiny
        void deleteEdge(const Place&,const Place&); //Delete edge between 2 vertex

        void deleteAllEdges(NodeVertex*); //receives a vertex, delete all the edges in that vertex, helpfull with the deleteVertex method

        void deleteEdgesConnections(const Place&); //recieves de destiny name, delete edges that are pointing to the vertex that we want to delete(edges that have that vertex for destiny)

        void deleteAll(void); //delete all the edges and vertexs of the graph

        std::string toString(void) const;

        void saveData(void); //Save the actual graph in file01

        void readData(void); //Read the file and insert into the graph
};


#endif // GRAPH_H_INCLUDED
