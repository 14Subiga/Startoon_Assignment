import numpy as np
import matplotlib.pyplot as plt
def load_data(filename):
    return np.loadtxt(filename)
def find_peaks_and_minima(signal):
    peaks = []
    minima = []
    for i in range(1, len(signal) - 1):
        if signal[i] > signal[i - 1] and signal[i] > signal[i + 1]:
            peaks.append(i)
        elif signal[i] < signal[i - 1] and signal[i] < signal[i + 1]:
            minima.append(i)
    return peaks, minima
def plot_signal(signal, peaks, minima):
    plt.figure(figsize=(10, 6))
    plt.plot(signal, label='Signal', color='black')
    plt.scatter(peaks, signal[peaks], color='red', label='Peaks', marker='o')
    plt.scatter(minima, signal[minima], color='blue', label='Minima', marker='o')
    plt.xlabel('Index')
    plt.ylabel('Signal Value')
    plt.title('Signal with Peaks and Minima')
    plt.legend()
    plt.grid(True)
    plt.show()
def main():
    signal = load_data('Data_1.txt') 
    peaks, minima = find_peaks_and_minima(signal)
    print(f"Peaks at indices: {peaks}")
    print(f"Minima at indices: {minima}")
    plot_signal(signal, peaks, minima)

if __name__ == "__main__":
    main()
