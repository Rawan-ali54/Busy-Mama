#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
template <class t>
class n
{
public:
	int priority;
	string info;
	n <t>* next;
};
template <class t>
class pqueue
{
	n<t> *head;
	int counter;
public:
	pqueue();
	void display();
	void delet();
	void deletspecific();
	void insert(string i, int p);
	void update_reminder();
	void edit();
	void deleteat(int);
	int postpone(string);
	void reminder();
	int lenght();
	void show();
};
template<class t>
class mothers
{
public:
	pqueue<t>task[7];
	int id;
	string name;
	string passwrod;


};