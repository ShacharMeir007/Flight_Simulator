//
// Created by shachar Meir on 03/11/2019.
//

#ifndef EX1_EX1_H
#define EX1_EX1_H

#include <string>
#include "Expression.h"
#include "Interpreter.h"
//Binary Expressions -start
class BinaryExpression : public Expression{
protected:
    Expression* leftExpression;
    Expression* rightExpression;
public:
    BinaryExpression(Expression* leftExpression,Expression* rightExpression);
    BinaryExpression(double, double);
    virtual ~BinaryExpression();
};
//Mul
class Mul: public BinaryExpression{
    double calculate() override;
public:
    Mul(Expression* el,Expression* er):BinaryExpression(el, er){}
    Mul(double l, double r):BinaryExpression(l,r){}
};
//Div
class Div: public BinaryExpression{
    double calculate() override;
public:
    Div(Expression* el,Expression* er):BinaryExpression(el, er){}
    Div(double l, double r):BinaryExpression(l,r){}
};
//Plus
class Plus: public BinaryExpression{
    double calculate() override;
public:
    Plus(Expression* el,Expression* er):BinaryExpression(el, er){}
    Plus(double l, double r):BinaryExpression(l,r){}
};
//Minus
class Minus: public BinaryExpression{
    double calculate() override;
public:
    Minus(Expression* el,Expression* er):BinaryExpression(el, er){}
    Minus(double l, double r):BinaryExpression(l,r){}
};
//Binary Expressions -end
//Unary Expressions -start
class UnaryExpression : public Expression{
protected:
    Expression* expression;
public:
  explicit UnaryExpression(Expression* expression);
  virtual ~UnaryExpression();

};
//UPlus
class UPlus: public UnaryExpression{
    double calculate() override;
public:
    UPlus(Expression* e):UnaryExpression(e){}
};
//UMinus
class UMinus: public UnaryExpression{
    double calculate() override;
public:
    UMinus(Expression* e):UnaryExpression(e){}
};
//Unary Expressions -end
class Variable:public Expression{
private:
    double value;
    std::string name;
    //Variable* copy;
public:
    Variable(const std::string&, double);

    Variable& operator ++() ;

    Variable& operator ++(int);

    Variable& operator --();
    Variable& operator --(int);

    Variable& operator +=(double);

    Variable& operator -=(double);

    double calculate() override;
    ~Variable() override;

    std::string getName() const;

    void setValue(double value);
};
class Value: public Expression{
    double value = 2;
public:
    explicit Value(double value);

    double calculate() override;
};
#endif //EX1_EX1_H
