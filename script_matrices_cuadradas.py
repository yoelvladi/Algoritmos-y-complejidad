import random

# Generar números y guardarlos en un archivo .txt con filas y columnas
def generar_archivo_matriz(nombre_archivo, filas):
    cantidad_numeros = (filas**2)*2  # Para dos matrices
    numeros = [random.randint(1, 100) for _ in range(cantidad_numeros)]
    
    with open(nombre_archivo, 'w') as archivo:
        # Escribir filas y columnas al inicio del archivo
        archivo.write(f"{filas}\n")
        for numero in numeros:
            archivo.write(f"{numero}\n")
    
    print(f"Archivo '{nombre_archivo}' generado con {filas} números para dos matrices.")

# Configura el nombre del archivo, filas y columnas
nombre_archivo = "matrices_cuadradas.txt"
filas = int(input("Ingresa numero: ")) # Número de filas de las matrices


generar_archivo_matriz(nombre_archivo, filas)