import random

# Generar números y guardarlos en un archivo .txt con filas y columnas
def generar_archivo_matriz(nombre_archivo, filas1, columnas1,filas2,columnas2):
    cantidad_numeros1 = filas1 * columnas1 # Para dos matrices
    cantidad_numeros2=filas2*columnas2
    numeros1 = [random.randint(1, 100) for _ in range(cantidad_numeros1)]
    numeros2 = [random.randint(1, 100) for _ in range(cantidad_numeros2)]
    
    with open(nombre_archivo, 'w') as archivo:
        # Escribir filas y columnas al inicio del archivo
        archivo.write(f"{filas1} {columnas1} {filas2} {columnas2}\n")
        for numero in numeros1:
            archivo.write(f"{numero}\n")
        for numero2 in numeros2:
            archivo.write(f"{numero2}\n")
    
    print(f"Archivo '{nombre_archivo}' .")

# Configura el nombre del archivo, filas y columnas
nombre_archivo = "numeros_matriz.txt"
filas1 = int(input("Ingresa filas: "))  # Número de filas de las matrices
columnas1 = int(input("Ingresa columnas: ")) # Número de columnas de las matrices
filas2= int(input("Ingresa filas: "))  # Número de filas de las matrices
columnas2=int(input("Ingresa columnas: ")) # Número de columnas de las matrices

generar_archivo_matriz(nombre_archivo, filas1, columnas1,filas2,columnas2)