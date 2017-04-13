//
//  Treasure.cpp
//  Google Code Jam 2013
//
//  Created by Kristopher Giesing on 4/12/13.
//  Copyright (c) 2013 Kristopher Giesing. All rights reserved.
//
#include <iostream>
#include <fstream>

#include <map>
#include <vector>
#include <set>

class Solver
{
public:
	Solver(unsigned long long radius, unsigned long long paint);
	
	void solve();
	void solveFast();
	
	unsigned long long getSolution() { return mRings; }
	
private:
	unsigned long long mRadius;
	unsigned long long mPaint;
	unsigned long long mRings;
	bool mEven;
};

Solver::Solver(unsigned long long radius, unsigned long long paint)
: mRadius(radius),
  mPaint(paint),
  mRings(0)
{
}

void
Solver::solve()
{
	while (mPaint >= 2*mRadius+1) {
		//std::cout << "Radius: " << mRadius << " Paint: " << mPaint << " Rings: " << mRings << std::endl;
		mPaint -= 2*mRadius+1;
		mRings++;
		mRadius += 2;
		//std::cout << ": Radius: " << mRadius << " Paint: " << mPaint << " Rings: " << mRings << std::endl;
	}
}

void
Solver::solveFast()
{
	this->solve();
}

int main(int argc, const char * argv[])
{
	std::string file = argv[1];
	std::ifstream in(file.c_str());
	file.replace(file.end()-6, file.end(), "out.txt");
	std::ofstream out(file.c_str());
	int nTests;
	in >> nTests;
	for (int i = 0; i < nTests; i++) {
		unsigned long long radius;
		unsigned long long paint;
		in >> radius;
		in >> paint;
		Solver solver(radius, paint);
		solver.solve();
		out << "Case #" << (i+1) << ": " << solver.getSolution();
		out << "\n";
	}
	
    return 0;
}
