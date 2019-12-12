#include "model.h"

LinearRegressionModel::LinearRegressionModel(const Dataset &data_train) {
	// Setting Variables
	data.copy(data_train);
	weights.init(data.number_predictor, 0);
}

LinearRegressionModel::LinearRegressionModel() {}

void LinearRegressionModel::print_weights() {
	char function_string[1000];
	printf("Number weights = %d\n", weights.number_weights);
	strcpy(function_string, "y = ");
	for (int i = 0; i < weights.number_weights; i++) {
		printf("Weights %d is = %f\n", i, weights.values[i]);
		char weight[20];
		sprintf(weight, "%.2f * x%d", weights.values[i], i);
		strcat(function_string, weight);
		if (i == weights.number_weights - 1) {
			strcat(function_string, "\n");
		}
		else {
			strcat(function_string, " + ");
		}
	}
	printf("%s\n", function_string);
}

void LinearRegressionModel::train(int max_iteration, float learning_rate) {

	// Mallocating some space for prediction
	float *y_pred = (float *)std::malloc(sizeof(float)*data.length);

	while (max_iteration > 0) {

		fit(y_pred);
		weights.update(data, y_pred, learning_rate);

		float mse = mean_squared_error(y_pred, data.y, data.length);

		if (max_iteration % 100 == 0) {
			print_weights();
			std::cout << "Iteration left: " << max_iteration << "; MSE = " << mse << "\n";
		}
		max_iteration--;
	}
	free(y_pred);
}

float LinearRegressionModel::predict(float *x) {
	float prediction = 0;
	for (int i = 0; i < weights.number_weights; i++) {
		prediction = prediction + weights.values[i] * x[i];
	}
	return prediction;
}

void LinearRegressionModel::fit(float *y_pred) {
	for (int i = 0; i < data.length; i++) {
		y_pred[i] = predict(data.X[i]);
	}
}
