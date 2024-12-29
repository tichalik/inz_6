import pandas as pd
from matplotlib import pyplot as plt

df = pd.read_csv("linear_times.csv")

plt.plot(df["mean"])
plt.show()
