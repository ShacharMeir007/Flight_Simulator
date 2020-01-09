//
// Created by shachar Meir on 03/11/2019.
//

#include "ex1.h"

#include <utility>
#include <iostream>

//BinaryExpression methods
BinaryExpression::BinaryExpression(Expression *leftExpression, Expression *rightExpression) {
    this->leftExpression = leftExpression;
    this->rightExpression = rightExpression;
}

BinaryExpression::~BinaryExpression(){
    delete(leftExpression);
    delete(rightExpression);
}

BinaryExpression::BinaryExpression(double left, double right) {
  this->leftExpression = new Value(left);
  this->rightExpression = new Value(right);
}

UnaryExpression::UnaryExpression(Expression *expression) {
    this->expression = expression;
}
UnaryExpression::~UnaryExpression() {
  delete(this->expression);
}

//Variable
Variable::Variable(const string& name, double value) {

    this->name = name;
    this->value = value;
}
Variable& Variable::operator++()  {
    this->value += 1;
    return *this;
}
Variable& Variable::operator++(int) {
    return ++*this;
}
Variable& Variable::operator--() {
    this->value -= 1;
    return *this;
}
Variable &Variable::operator--(int) {
    return --*this;
}
Variable& Variable::operator+=(double val) {
    this->value += val;
    return *this;
}
Variable& Variable::operator-=(double val) {
    this->value -= val;
    return *this;
}
double Variable::calculate() {
    return this->value;
}


Variable::~Variable(){

}

string Variable::getName() const {
    return name;
}

void Variable::setValue(double value) {
    Variable::value = value;
}

//Value
Value::Value(double value) {
    this->value = value;
}
double Value::calculate() {
    return value;
}
//Mul
double Mul::calculate() {
    return this->leftExpression->calculate() * this->rightExpression->calculate();
}
//Div
double Div::calculate() {
    double rightExpressionValue = this->rightExpression->calculate();
    if (rightExpressionValue==0) {
            throw "division by zero";
    }
    return this->leftExpression->calculate() / this->rightExpression->calculate();
}
//Plus
double Plus::calculate() {
    return this->leftExpression->calculate() + this->rightExpression->calculate();
}
//Minus
double Minus::calculate() {
    return this->leftExpression->calculate() - this->rightExpression->calculate();
}
//UPlus
double UPlus::calculate() {
    return this->expression->calculate();
}
//UMinus
double UMinus::calculate() {
    return -1 *this->expression->calculate();
}