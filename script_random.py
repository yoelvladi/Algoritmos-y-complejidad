import random
def generar_archivo_numeros(nombre_archivo, cantidad_numeros):
    numeros = list(range(1, cantidad_numeros + 1))
    with open(nombre_archivo, 'w') as archivo:
        for numero in numeros:
            rand = random.randint(0,10**7)
            archivo.write(f"{rand}\n")
    print(f"Archivo '{nombre_archivo}' generado con {cantidad_numeros} números ordenados.")

# Configura el nombre del archivo y la cantidad de números
nombre_archivo = "numeros_random.txt"
cantidad_numeros = int(input("Ingresa un numero: "))  # Cambia este valor según sea necesario

generar_archivo_numeros(nombre_archivo, cantidad_numeros)