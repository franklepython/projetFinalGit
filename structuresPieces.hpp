#pragma once
#include <iostream>
#include <string>
// ne pas utiliser namespace std

class Echiquier {

public:
	Echiquier() = default;
	~Echiquier() = default;

private:
	int echiquier[8][8]; // contient des pointeurs vers des pieces
};


class Piece {
public:
	Piece(std::string nom, std::string couleur, std::shared_ptr<Echiquier> ptrEchiquier) : nom_(nom), couleur_(couleur), ptrEchiquier_(ptrEchiquier){}
	Piece() = default;
	virtual ~Piece() {};

	virtual bool moveEstLegal() const = 0;

protected:
	std::string nom_;
	std::string couleur_;
	int pos_[2];
	std::shared_ptr<Echiquier> ptrEchiquier_;
};


class Roi : public Piece {

public:
	Roi(std::string nom, std::string couleur, std::shared_ptr<Echiquier> ptrEchiquier) : nom_(nom), couleur_(couleur), ptrEchiquier_(ptrEchiquier){};
	~Roi() = default;


private:
	std::string nom_;
	std::string couleur_;
	int pos_[2];
	std::shared_ptr<Echiquier> ptrEchiquier_;

	virtual bool moveEstLegal() const override;
};



/*class Pion : public Piece {
public:
	Pion(std::string nom, std::string couleur) : nom_(nom), couleur_(couleur) {};
	~Pion() = default;


private:
	
	std::string nom_;
	std::string couleur_;
	virtual bool moveEstLegal() const override;
};



class Tour : public Piece {
public:

	Tour(std::string nom, std::string couleur, Echiquier* ptrEchiquier) : Piece(nom, couleur) {};
	~Tour();


private:

	std::string nom_;
	std::string couleur_;
	virtual bool moveEstLegal() const override;

};*/


