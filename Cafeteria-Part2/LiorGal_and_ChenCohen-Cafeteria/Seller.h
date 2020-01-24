#ifndef __SELLER_H
#define __SELLER_H

class Seller
{
private:
	char* name;
	int seniority;

public:
	// c'tor & d'tor
	Seller(const char* name, int seniority) throw (const char*);
	Seller(const Seller& other);
	const Seller& operator=(const Seller& other);
	~Seller();

	// Getters
	const char* getName() const;
	int getSeniority() const;

	// Setters
	void setName(const char* newName);
	void setSeniority(int seniority) throw (const char*);
};

#endif
