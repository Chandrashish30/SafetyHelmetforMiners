# SafetyHelmetforMiners
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
- [Dataset](#dataset)
- [Dependencies](#dependencies)
- [Installation](#installation)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

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
python```

###Temperature Prediction
python
Copy code
# Code snippet for Temperature Prediction
# (Refer to Python script for detailed implementation)
Humidity Prediction
python
Copy code
# Code snippet for Humidity Prediction
# (Refer to Python script for detailed implementation)
In the provided Python script, we utilize machine learning techniques, specifically the RandomForestRegressor from scikit-learn, to predict Methane Concentration, Temperature, and Humidity based on the collected dataset. The script evaluates model performance using mean squared error and R2 score metrics.

Usage
Clone the repository.
Install the required dependencies (see Dependencies).
Run the Python script for data analysis and prediction.
Dataset
The dataset used for this analysis was obtained from Elsevier and consists of environmental data collected from an active coal mine in China. The dataset provides valuable insights into factors contributing to safety hazards in mining operations.

Dependencies
pandas
scikit-learn
Install dependencies using:

bash
Copy code
pip install pandas scikit-learn
Installation
No specific installation steps are required for this component. Ensure you have Python installed, and install the necessary dependencies.

Contributing
Fork the repository.
Create a new branch (git checkout -b feature/new-feature).
Make changes and commit (git commit -am 'Add new feature').
Push to the branch (git push origin feature/new-feature).
Create a pull request.
