import random

# Generar números semi ordenados y guardarlos en un archivo .txt
def generar_archivo_numeros_semi_ordenados(nombre_archivo, cantidad_numeros, desorden=5):
    numeros = list(range(1, cantidad_numeros + 1))
    
    # Introducir desorden en la lista
    for _ in range(desorden):
        i = random.randint(0, cantidad_numeros - 1)
        j = random.randint(0, cantidad_numeros - 1)
        numeros[i], numeros[j] = numeros[j], numeros[i]
    
    with open(nombre_archivo, 'w') as archivo:
        for numero in numeros:
            archivo.write(f"{numero}\n")
    
    print(f"Archivo '{nombre_archivo}' generado con números semi ordenados.")

# Configura el nombre del archivo, la cantidad de números y el nivel de desorden
nombre_archivo = "numeros_semi_ordenados.txt"
cantidad_numeros = int(input("ingresa numero: "))  # Cambia este valor según sea necesario
desorden = int((cantidad_numeros)/3) # Número de intercambios para desordenar los números

generar_archivo_numeros_semi_ordenados(nombre_archivo, cantidad_numeros, desorden)
