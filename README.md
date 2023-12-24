# Mining Safety Helmet Data Analysis and Prediction

## Overview

Mining operations involve inherent risks, especially concerning the safety of miners. This project addresses these challenges by introducing a data collection safety helmet equipped with sensors, including an MPU6050 IMU, MQ4 gas sensor, DHT11 temperature and humidity sensor, and GPS. The helmet is designed to collect and transmit real-time data, enabling early detection of potential dangers. This README provides insights into the data analysis and predictive modeling aspects of the project.

## Table of Contents

- [Project Overview](#overview)
- [Data Analysis and Prediction](#data-analysis-and-prediction)
  - [Methane Concentration Prediction](#methane-concentration-prediction)
  - [Temperature Prediction](#temperature-prediction)
  - [Humidity Prediction](#humidity-prediction)
- [Usage](#usage)
- [Dependencies](#dependencies)


## Data Analysis and Prediction

### Methane Concentration Prediction

```python
# Load the dataset
data = pd.read_csv('C:/Users/chand/Dropbox/MyPC(LAPTOP OQ4HQNUC)/Downloads/database_iot9.csv')

# Extract features and target variable for Methane Concentration
X = data[['year', 'month', 'day', 'hour', 'minute', 'second', 'temperature', 'relative_humidity']]
y = data[['methane_concentration']]

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Initialize the random forest regressor
rf = RandomForestRegressor(n_estimators=600, max_depth=15, max_features=8, min_samples_split=5, random_state=40)

# Fit the model to the training data
rf.fit(X_train, y_train)

# Predict the target variables for the testing data
y_pred = rf.predict(X_test)

# Calculate the mean squared error and R2 score of the model
mse = mean_squared_error(y_test, y_pred)
r2 = r2_score(y_test, y_pred)

print('Mean squared error for Methane concentration:', mse)
print('R2 score for Methane Concentration:', r2)
```
### Temperature Prediction

```python
# Extract features and target variable for Temperature
X1 = data[['year', 'month', 'day', 'hour', 'minute', 'second', 'methane_concentration', 'relative_humidity']]
y1 = data[['temperature']]

# Split the data into training and testing sets
X1_train, X1_test, y1_train, y1_test = train_test_split(X1, y1, test_size=0.2, random_state=42)

# Initialize the random forest regressor
rf1 = RandomForestRegressor(n_estimators=600, max_depth=15, max_features=8, min_samples_split=5, random_state=40)

# Fit the model to the training data
rf1.fit(X1_train, y1_train)

# Predict the target variables for the testing data
y1_pred = rf1.predict(X1_test)

# Calculate the mean squared error and R2 score of the model
mse1 = mean_squared_error(y1_test, y1_pred)
r21 = r2_score(y1_test, y1_pred)

print('Mean squared error for Temperature:', mse1)
print('R2 score for Temperature:', r21)
```
### Humidity Prediction
```python
# Extract features and target variable for Humidity
X2 = data[['year', 'month', 'day', 'hour', 'minute', 'second', 'temperature', 'methane_concentration']]
y2 = data[['relative_humidity']]

# Split the data into training and testing sets
X2_train, X2_test, y2_train, y2_test = train_test_split(X2, y2, test_size=0.2, random_state=42)

# Initialize the random forest regressor
rf2 = RandomForestRegressor(n_estimators=600, max_depth=15, max_features=8, min_samples_split=5, random_state=40)

# Fit the model to the training data
rf2.fit(X2_train, y2_train)

# Predict the target variables for the testing data
y2_pred = rf2.predict(X2_test)

# Calculate the mean squared error and R2 score of the model
mse2 = mean_squared_error(y2_test, y2_pred)
r22 = r2_score(y2_test, y2_pred)

print('Mean squared error for Humidity:', mse2)
print('R2 score for Humidity:', r22)

```
In the provided Python script, we utilize machine learning techniques, specifically the RandomForestRegressor from scikit-learn, to predict Methane Concentration, Temperature, and Humidity based on the collected dataset. The script evaluates model performance using mean squared error and R2 score metrics.

## Usage
Clone the repository.
Install the required dependencies (see Dependencies).
Run the Python script for data analysis and prediction.

## Dependencies
pandas
scikit-learn
Install dependencies using:

```python
pip install pandas scikit-learn
```



