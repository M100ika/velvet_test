import requests
import zlib


url = 'https://smart-farm.kz:8502/api/v2/ActualScalesFirmware'
params = {'serialNumber':'84271C84DBE8', 'firmwareVersion':'velvet_stm_0.0.2.hex'}

response = requests.get(url, params=params)
headers = response.headers
version = headers.get('Version')
crc = headers.get('CRC')
print(headers)
print(response.status_code)
if response.status_code == 200:
    with open('firmware.bin', 'wb') as f:
        f.write(response.content)
else:
    print(f"Error")



# Открываем файл и считаем его контрольную сумму
with open('firmware.bin', 'rb') as f:
    file_hash = zlib.crc32(f.read())

# Преобразуем полученную контрольную сумму в строку в формате CRC32
file_hash_crc32 = format(file_hash & 0xFFFFFFFF, '08x')

# Сравниваем полученную контрольную сумму с той, что указана в заголовках
if file_hash_crc32 == 'af5ec79d':
    print('Контрольная сумма совпадает')
else:
    print('Контрольная сумма не совпадает')