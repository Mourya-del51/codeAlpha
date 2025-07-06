import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Load dataset
df = pd.read_csv("titanic.csv")

# Create output directory
import os
os.makedirs("output", exist_ok=True)

# Age Distribution
plt.figure(figsize=(8, 5))
sns.histplot(df['Age'].dropna(), kde=True, color='skyblue')
plt.title('Age Distribution of Passengers')
plt.savefig("output/age_distribution.png")

# Survival Count by Class
plt.figure(figsize=(8, 5))
sns.countplot(x='Pclass', hue='Survived', data=df)
plt.title('Survival by Passenger Class')
plt.savefig("output/survival_by_class.png")

# Gender vs Survival
plt.figure(figsize=(8, 5))
sns.countplot(x='Sex', hue='Survived', data=df)
plt.title('Survival by Gender')
plt.savefig("output/gender_survival.png")

print("Visualizations saved in 'output' folder.")
