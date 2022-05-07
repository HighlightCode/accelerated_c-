#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#define ANNOTATE 0

#include <algorithm>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

/*-----------------
		Core
-----------------*/
class Core {
	friend class Student_info;
	friend class Audit;

public:
	Core() : midterm(0), final(0) {
#if ANNOTATE == 1
		std::cerr << "Core::Core() Default Constructor" << std::endl;
#endif
	}

	// build a Core from istream
	Core(std::istream &is) {
#if ANNOTATE == 1
		std::cerr << "CORE::CORE(istream&) Constructor" << std::endl;
#endif
		read(is);
	}
	virtual ~Core() {
	}

	std::string name() const;
	virtual double grade() const;
	std::string letter_grade() const;
	virtual std::istream &read(std::istream &);

	bool valid() const {
		return !homework.empty();
	}
	virtual bool requirements_met() const {
		return std::find(homework.begin(), homework.end(), 0.0) ==
			homework.end();
	}

protected:
	virtual Core *clone() const {
		return new Core(*this);
	}
	std::istream &read_common(std::istream &);
	double midterm, final;
	std::vector<double> homework;

private:
	std::string n;
};

/*-----------------
		Grad
-----------------*/
class Grad : public Core {
public:
	// both constructors implicitly use Core::Core() to initialize the base part
	Grad() : thesis(0) {
#if ANNOTATE == 1
		std::cerr << "Grad::Grad() Default Constructor" << std::endl;
#endif
	}

	Grad(std::istream &is) {
#if ANNOTATE == 1
		std::cerr << "Grad::Grad(istream&) Constructor" << std::endl;
#endif
		read(is);
	}

	double grade() const;
	std::istream &read(std::istream &);
	bool requirements_met() const {
		return Core::requirements_met() && thesis != 0.0;
	}

protected:
	Grad *clone() const {
		return new Grad(*this);
	}

private:
	double thesis;
};

/*-----------------
	Student_info
-----------------*/
class Student_info {
public:
	Student_info() : cp(0) {
	}
	Student_info(std::istream &is) : cp(0) {
		read(is);
	}
	Student_info(const Student_info &);
	Student_info &operator=(const Student_info &);
	~Student_info() {
		delete cp;
	}

	// operator
	std::istream &read(std::istream &);

	std::string name() const {
		if (cp)
			return cp->name();
		else
			throw std::runtime_error("uninitialized Student !");
	}

	double grade() const {
		if (cp)
			return cp->grade();
		else
			throw std::runtime_error("uninitialized Student");
	}
	static bool compare(const Student_info &s1, const Student_info &s2) {
		return s1.name() < s2.name();
	}

private:
	Core *cp;
};

bool compare(const Core &, const Core &);
bool compare_Core_pts(const Core *, const Core *);
std::istream &read_hw(std::istream &, std::vector<double> &);
double grade(double, double, const std::vector<double> &);
double grade(double, double, double homework);
double median(std::vector<double>);

/*-----------------
	Credit Class
-----------------*/
class Credit : public Core {
public:
	Credit() {
	}
	Credit(std::istream &is) {
		read(is);
	}

	double grade() const {
		if (homework.empty())
			return (final + midterm) / 2;
		else
			return Core::grade();
	}
	bool valid() const {
		return midterm > 0 || final > 0;
	}
	std::string is_passed() const {
		return grade() > 60 ? "P" : "F";
	}

protected:
	Credit *clone() const {
		return new Credit(*this);
	}
};

/*-----------------
	Audit Class
-----------------*/
class Audit : public Core {
public:
	Audit() {
	}
	Audit(std::istream &is) {
		read(is);
	}

	std::istream &read(std::istream & in) {
		in >> n;
		return in;
	}

	double grade() const {
		return 0.0;
	};

	bool valid() const {
		return true;
	}
	bool requirements_met() const {
		return true;
	}

protected:
	Audit *clone() const {
		return new Audit(*this);
	}
};

#endif
