import pandas as pd 
from sklearn.tree import DecisionTreeRegressor, export_graphviz 
from sklearn.ensemble import RandomForestRegressor 
from sklearn.model_selection import train_test_split 
from sklearn.metrics import mean_squared_error, r2_score 
 
 
# Load the dataset 
data=pd.read_csv('"C:/Users/chand/Dropbox/MyPC(LAPTOP
OQ4HQNUC)/Downloads/database_iot9.csv"') 
 
####### METHANE CONCENTRATION ######### 
# Split the dataset into input features and target variables 
X=df[['year','month','day','hour','minute','second','temperature','relativ
 e_humidity']] 
y = df[['methane_concentration']] 
 
# Split the data into training and testing sets 
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, 
random_state=42) 
 
# Initialize the random forest regressor 
rf = RandomForestRegressor(n_estimators=600, max_depth=15, max_features=8, 
min_samples_split=5, random_state=40) 
 
# Fit the model to the training data 
rf.fit(X_train, y_train) 
 
# Predict the target variables for the testing data 
y_pred = rf.predict(X_test) 
 
# Calculate the mean squared error and R2 score of the model 
mse = mean_squared_error(y_test, y_pred) 
r2 = r2_score(y_test, y_pred) 
 
print('Mean squared error for Methane concentration:', mse) 
print('R2 score Methane Concentration:', r2) 
 
 
###### Temperature ######### 
# Split the dataset into input features and target variables 
X1=df[['year','month','day','hour','minute','second','methane_concentratio
 n','relative_humidity']] 
y1 = df[['temperature']] 
 
# Split the data into training and testing sets 
X1_train,X1_test,y1_train,y1_test= train_test_split(X1, y1, test_size=0.2, 
random_state=42) 
 
# Initialize the random forest regressor 
rf1=RandomForestRegressor(n_estimators=600, max_depth=15, max_features=8, 
min_samples_split=5, random_state=40) 
 
# Fit the model to the training data 
rf1.fit(X1_train, y1_train) 
 
# Predict the target variables for the testing data 
y1_pred = rf1.predict(X1_test) 
 
# Calculate the mean squared error and R2 score of the model 
mse1 = mean_squared_error(y1_test, y1_pred) 
r21 = r2_score(y1_test, y1_pred) 
 
print('Mean squared error for Temperature:', mse1) 
print('R2 score for temperature:', r21) 
 
 
 
 
###### Humidity ######### 
# Split the dataset into input features and target variables 
X2=df[['year','month','day','hour','minute','second','temperature','methan
 e_concentration']] 
y2 = df[['relative_humidity']] 
 
# Split the data into training and testing sets 
X2_train,X2_test,y2_train,y2_test= train_test_split(X2, y2, test_size=0.2, 
random_state=42) 
 
# Initialize the random forest regressor 
rf2 =RandomForestRegressor(n_estimators=600, max_depth=15, max_features=8, 
min_samples_split=5, random_state=40) 
 
# Fit the model to the training data 
rf2.fit(X2_train, y2_train) 
 
# Predict the target variables for the testing data 
y2_pred = rf2.predict(X2_test) 
 
# Calculate the mean squared error and R2 score of the model 
mse2 = mean_squared_error(y2_test, y2_pred) 
r22 = r2_score(y2_test, y2_pred) 
 
print('Mean squared error for Humidity:', mse2) 
print('R2 score for Humidity:', r22)
