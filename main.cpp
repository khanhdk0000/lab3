#include <bits/stdc++.h>

using namespace std;

class node{
    private:
    int compare(node & that) {
        // TODO
        if(this->digit > that.digit) return 1;
        if(this->digit == that.digit) return 0;
        if(this->digit < that.digit) return -1;
    }
    int digit=0;
    node * prev=0;

    public:


    node(){
		//TODO
		digit = 0;
		prev = NULL;
	}
    node(long int d) {
        //TODO
        if(d != 0)
        {
            digit = d%10000;
            if(d/10000 != 0)
            {
                prev = new node(d/10000);
            }

        }
    }
    node(string str){
        //TODO
        bool isMinus = false;
        if(str[0] == '-')
            isMinus = true;
        if(str.length() > 0)
        {
            int sizeTem = 0;
            bool isValid = true;
            if(str.length() <= 4)
            {
                sizeTem = 0;
                isValid = false;
            }
            else
            {
                sizeTem = str.length() - 4;
            }
                string tem = str.substr(sizeTem);
                for(int i = 0; i < tem.length();i++)
                {
                    digit = 10*digit + (tem[i] - '0');
                }
                if(isMinus)
                {
                    digit = -digit;
                }
            prev = NULL;
            if(isValid)
            {
                prev = new node(str.substr(0, str.length() - 4));
            }

        }
    }
    node(node & that){
        //TODO
    }
    node(node && that){
        //TODO
    }
    void operator=(node & that){
        //TODO
    }
    void operator=(node && that){
        //TODO
    }
    ~node(){
       //TODO
    }
    void modify(){
        //TODO
        //this->print();
        if(this->digit != 0 && this->prev != NULL)
        {
            node *pCur = new node();
            pCur = this->prev;
            node *pPre = new node();
            while(pCur->prev)
            {
                pPre = pCur;
                pCur = pCur->prev;
            }
            if(pCur->digit == 0 && pCur->prev == NULL)
            {
                pPre->prev = NULL;
                delete pCur;
            }
        }

    }

    node operator+(long int d) {
        //TODO

    }
    node operator-(long int d){
        //TODO
    }
    node operator*(long int d){
        //TODO
    }
    node operator-(){
        //TODO
    }
    node operator+(node & that){
        //TODO
        string addNum = "", thisNum = "", thatNum = "";
        node *pTem = this, *pTem2 = &that;
        while(pTem)
        {
            thisNum.insert(0,to_string(pTem->digit));
            pTem = pTem->prev;
        }
        while(pTem2)
        {
            thatNum.insert(0,to_string(pTem2->digit));
            pTem2 = pTem2->prev;
        }
        if(thisNum.length() > thatNum.length())
        {
            swap(thisNum, thatNum);
        }
        int num1 = thisNum.length(), num2 = thatNum.length();
        int carry = 0;
        reverse(thisNum.begin(), thisNum.end());
        reverse(thatNum.begin(), thatNum.end());
        for(int i = 0; i < num1; i++)
        {
            int sum = ((thisNum[i] - '0') + (thatNum[i] - '0') + carry);
            addNum.push_back(sum%10 + '0');
            carry = sum/10;
        }
        for(int i = num1; i < num2; i++)
        {
            int sum = ((thatNum[i] - '0') + carry);
            addNum.push_back(sum%10 + '0');
            carry = sum/10;
        }
        if(carry)
        {
            addNum.push_back(carry + '0');
        }
        reverse(addNum.begin(), addNum.end());
        node res(addNum);
        //res.print();
        return res;

    }

    node operator-(node & that){
       //TODO
        string addNum = "", thisNum = "", thatNum = "";
        int trigger = 0;
        node *pTem = this, *pTem2 = &that;
        if((pTem->digit > 0) && (pTem2->digit > 0))
        {
            trigger = 1;
        }
        else if((pTem->digit > 0) && (pTem2->digit < 0))
        {
            trigger = 2;
        }
        else if((pTem->digit < 0) && (pTem2->digit > 0))
        {

        }
        else if((pTem->digit < 0) && (pTem2->digit < 0))
        {

        }
        if(trigger == 1)
        {
            while(pTem)
            {
                thisNum.insert(0,to_string(pTem->digit));
                pTem = pTem->prev;
            }
            while(pTem2)
            {
                thatNum.insert(0,to_string(pTem2->digit));
                pTem2 = pTem2->prev;
            }
            if(thisNum.length() > thatNum.length())
            {
                swap(thisNum, thatNum);
            }
            int num1 = thisNum.length(), num2 = thatNum.length();
            int carry = 0;
            reverse(thisNum.begin(), thisNum.end());
            reverse(thatNum.begin(), thatNum.end());
            for(int i = 0; i < num1; i++)
            {
                int sum = ((thisNum[i] - '0') + (thatNum[i] - '0') + carry);
                addNum.push_back(sum%10 + '0');
                carry = sum/10;
            }
            for(int i = num1; i < num2; i++)
            {
                int sum = ((thatNum[i] - '0') + carry);
                addNum.push_back(sum%10 + '0');
                carry = sum/10;
            }
            if(carry)
            {
                addNum.push_back(carry + '0');
            }
            reverse(addNum.begin(), addNum.end());
            node res(addNum);
            return res;
        }
        else if(trigger == 2)
        {

        }

    }

    node operator*(node & that){
        //TODO
    }

    void print(){
        if (prev==0) {
            cout<<'|'<<digit<<'|';
            return;
        }
        prev->print();
        cout<<'|'<<digit<<'|';
        return;
    }


    bool operator>(node & that){
        this->modify();
        that.modify();
        if (this->compare(that)==1) return true;
        return false;
    }

    bool operator<(node & that){
        this->modify();
        that.modify();
        if (this->compare(that)==-1) return true;
        return false;
    }

    bool operator>=(node & that){
        this->modify();
        that.modify();
        if (this->compare(that)>-1) return true;
        return false;
    }

    bool operator<=(node & that){
        this->modify();
        that.modify();
        if (this->compare(that)<1) return true;
        return false;
    }

    bool operator==(node & that){
        this->modify();
        that.modify();
        if (this->compare(that)==0) return true;
        return false;
    }

};

int main(int argc, char* argv[]) {
    ifstream inFile;
	string command;
	inFile.open("input.txt");
	node * a=0;
	node * b=0;
	long int c =0;
	long int d =0;
	string e;
	string f;
	if (!inFile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}
	while(inFile>>command){
		if (command=="con_empty") {
			a= new node();
			a->modify();
			a->print();
			cout<<"\n";
			delete a;
		}
		if (command=="con_long") {
			inFile>>c;
			a=new node(c);
			a->modify();
			a->print();
			cout<<"\n";
			delete a;
		}
		if (command=="con_string") {
			inFile>>e;
			a=new node(e);
			a->modify();
			a->print();
			cout<<"\n";
			delete a;
		}
		if (command=="con_copy") {
			inFile>>e;
			b= new node(e);
			b->modify();
			b->print();
			cout<<"\n";
			a= new node(*b);
			delete b;
			a->modify();
			a->print();
			cout<<"\n";
			delete a;
		}
		if (command=="con_move") {
			inFile>>e>>c;
			a=new node(e);
			a->modify();
			a->print();
			cout<<"\n";
			b= new node(*a+c);
			b->modify();
			b->print();
			cout<<"\n";
			delete a,b;
		}
		if (command=="ass_copy") {
			inFile>>e;
			b= new node(e);
			b->modify();
			b->print();
			cout<<"\n";
			a= new node(0);
			*a=*b;
			delete b;
			a->modify();
			a->print();
			cout<<"\n";
			delete a;
		}
		if (command=="ass_move") {
			inFile>>e>>c;
			a=new node(e);
			a->modify();
			a->print();
			cout<<"\n";
			b= new node(0);
			*b=*a+c;
			b->modify();
			b->print();
			cout<<"\n";
			delete a,b;
		}
		if (command=="comp") {
			inFile>>e>>f;
			a=new node(e);
			b=new node(f);
			a->modify();
			b->modify();
			cout<<(*a < *b)<<"\n";
			cout<<(*a > *b)<<"\n";
			cout<<(*a == *b)<<"\n";
			delete a;
		}
		if (command=="add_with_num") {
			inFile>>e>>c;
			a=new node(e);
			(*a+c).print();
			cout<<"\n";
			delete a;
		}
		if (command=="sub_with_num") {
			inFile>>e>>c;
			a=new node(e);
			(*a-c).print();
			cout<<"\n";
			delete a;
		}
		if (command=="mul_with_num") {
			inFile>>e>>c;
			a=new node(e);
			(*a*c).print();
			cout<<"\n";
			delete a;
		}
		if (command=="negative") {
			inFile>>e;
			a=new node(e);
			(-(*a)).print();
			cout<<"\n";
			delete a;
		}
		if (command=="add") {
			inFile>>e>>f;
			a=new node(e);
			b=new node(f);
			(*a+*b).print();
			cout<<"\n";
			delete a;
		}
		if (command=="sub") {
			inFile>>e>>f;
			a=new node(e);
			b=new node(f);
			(*a+*b).print();
			cout<<"\n";
			delete a;
		}
		if (command=="mul") {
			inFile>>e>>f;
			a=new node(e);
			b=new node(f);
			((*a)*(*b)).print();
			cout<<"\n";
			delete a;
		}
	}
	inFile.close();
	return 0;
}
