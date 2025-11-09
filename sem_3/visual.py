import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

df = pd.read_csv('shell_sort_benchmark.csv')

# heat map
plt.figure (figsize=(10, 6))
pivot_data = df.pivot_table (values='TimeMicroseconds', index=['Algorithm', 'Data_t'], columns='Size')
sns.heatmap (pivot_data, annot=True, fmt='.0f', cmap='YlOrRd', linewidths=0.5)
plt.title ('Heat map of the execution time', fontweight='bold')
plt.tight_layout()
plt.savefig ('img/heatmap.png', dpi=300)
plt.show()
