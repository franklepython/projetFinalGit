#pragma once
#include <iostream>
#include <string>
// ne pas utiliser namespace std

class Echiquier {

public:
	Echiquier() = default;
	~Echiquier();

	void ajouterPiece(Piece piece, int pos);
	void peutAjouterPiece(Piece piece, int pos); 
	friend class Piece;

private:
	int nPieces_ = 0;
	static const int nPiecesMax_ = 64;
	int echiquier[nPiecesMax_-1];
};


// Une classe abstraite pour représenter une pièce
// Chaque piece va voir un echiquier commun comme attribut
class Piece {
public:
	Piece(std::string couleur) : couleur_(couleur) {}
	virtual ~Piece() {};

	virtual void avancer() = 0;

protected:
	std::string couleur_ ;
};


class Roi : public Piece {

public:
	Roi(std::string nom, std::string couleur, Echiquier* ptrEchiquier) : Piece(couleur), echiquier_(ptrEchiquier) {};
	~Roi();


private:
	Echiquier* echiquier_;

};



class Pion : public Piece {
public:
	Pion(std::string nom, std::string couleur, Echiquier* ptrEchiquier) : Piece(couleur), echiquier_(ptrEchiquier) {};
	~Pion();

private:
	Echiquier* echiquier_;

};



class Tour : public Piece {
public:

	Tour(std::string nom, std::string couleur, Echiquier* ptrEchiquier) : Piece(couleur), echiquier_(ptrEchiquier) {};
	~Tour();

private:
	Echiquier* echiquier_;

};


