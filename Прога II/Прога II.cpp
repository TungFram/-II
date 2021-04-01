#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;


class CPolynom
{
private:
	vector <int> extents_;
	vector <int> coefficents_;
public:
	CPolynom() { /*SetPolynom(0);*/ }
	CPolynom(vector <int> PlentyOfNumbers) { SetPolynom(PlentyOfNumbers); }

	void SetPolynom(vector <int> PlentyOfNumbers)
	{
		for (int i = 0; i < PlentyOfNumbers.size(); i++)
		{
			coefficents_[i] = PlentyOfNumbers[i];
		}
	}
	void GetPolynom();

	int Get_coef(int i) { return coefficents_[i]; }
	int Get_ext(int i) { return extents_[i]; }

	void Set_coef(int i) { coefficents_[i] = i; }
	void Set_extent(int i) { extents_[i] = i; }

	vector <int> Get_All_coeff() { return coefficents_; }
	vector <int> Get_All_exts() { return extents_; }
	void Set_All_Polynom(int i) { coefficents_.reserve(i); extents_.reserve(i); }


	CPolynom operator= (const CPolynom& another)
	{
		this->coefficents_ = another.coefficents_;
		this->extents_ = another.extents_;
		return *this;
	}

	CPolynom& operator-(const CPolynom& another)
	{
		int help;
		for (int i = 0; i < another.coefficents_.size(); i++)
		{
			help = another.coefficents_[i];
			this->coefficents_[help] = (this->coefficents_[help] * -1);
		}
		return *this;
	}
	friend const CPolynom& operator+ (const	CPolynom& polynom) { return polynom; }

	bool operator== (const CPolynom& another)
	{
		return (this->coefficents_ == another.coefficents_
			&& this->extents_ == another.extents_);
	}
	bool operator!= (const CPolynom& another)
	{
		return (this->coefficents_ != another.coefficents_
			|| this->extents_ != another.extents_);
	}

	friend CPolynom operator+ ();
	friend CPolynom operator- ();
	friend CPolynom operator+= ();
	friend CPolynom operator-= ();

	friend CPolynom operator* ();
	friend CPolynom operator/ ();
	friend CPolynom operator*= ();
	friend CPolynom operator/= ();

	CPolynom operator[] ();
	~CPolynom() { coefficents_.clear();  extents_.clear(); }
};
	

ostream& operator<< (ostream& stream, CPolynom& polynom)
{
	cout << "(";
	for (int i = 0; i < polynom.Get_All_coeff().size() - 1; i++)
	{
		cout << "(" << polynom.Get_coef(i) << "x^" << polynom.Get_ext(i) << ") + ";
	}
	cout << "(" << polynom.Get_coef(polynom.Get_All_coeff().size() - 1) << "x^" << polynom.Get_ext(polynom.Get_All_coeff().size() - 1) << ")";
}
istream& operator<< (istream& stream, CPolynom& polynom)
{
	int index;
	int extent;
	int maxExtent = 0;
	cin >> maxExtent;
	if(!isdigit(maxExtent))
	{
		throw exception("Error: invalid reading max!");
	}
	polynom.Set_All_Polynom(maxExtent);
	for (int i = 0; i < maxExtent; i++)
	{
		cin >> extent >> index;
		if ((!isdigit(extent)) || (!(isdigit(index))))
		{
			throw exception("Error: invalid reading!");
		}
		polynom.Set_coef(index);
		polynom.Set_extent(extent);
	}

}

vector <int> AskForCreatePolynom(vector <int> PlentyOfNumbers, char* polynom_string)
{
	/*cout << "Enter your polynom: ";
	cin >> polynom_string;

	cout << polynom_string;*/

	return PlentyOfNumbers;
}
int main()
{
	vector <int> PlentyOfNumbers;
	char polynom[100];

	//PlentyOfNumbers = AskForCreatePolynom(PlentyOfNumbers, polynom);
	//CPolynom Polynom(PlentyOfNumbers);

	cout << "Enter your polynom: ";
	gets(polynom);
	

	cout << polynom;
	return 0;
}

//    5 * x^2 + 6 * x - 100
//    5*x^2 + 6*x - 100
//    5x^2 + 6x - 100}