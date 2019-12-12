#pragma once
#include "utils.h"

class LinearRegressionModel {
	Dataset data;
	Weights weights;

public:
	LinearRegressionModel();
	LinearRegressionModel(const Dataset & data_train);
	void print_weights();
	void train(int max_iteration, float learning_rate);
	float predict(float *x);
private:
	void fit(float *y_pred);
};