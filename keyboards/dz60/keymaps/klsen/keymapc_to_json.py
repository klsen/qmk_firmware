#!/usr/bin/python3

# Converts the layout in keymap.c to json so I can use the QMK Configurator to give me pictures.
# Based on the JSON outputs given by QMK Configurator.
#
# Kenneth Seneres
# Sept. 2, 2020

# write in the other fields here
version = 1
notes = "my keymap"
documentation = "This is from my keymap.c to json converter."
keyboard = "dz60"
keymap = "klsen"
layout = "LAYOUT_all"
author = "Kenneth Seneres"
layout_rows = 5         # not a json field but important anyway

keymap_c = open('keymap.c', 'r')
keymap_json = open(keymap + '.json', 'w')

# start of file writing
keymap_json.write('{\n')
keymap_json.write('\t\"version\": ' + str(version) + ',\n')
keymap_json.write('\t\"notes\": \"' + notes + '\",\n')
keymap_json.write('\t\"documentation\": \"' + documentation + '\",\n')
keymap_json.write('\t\"keyboard\": \"' + keyboard + '\",\n')
keymap_json.write('\t\"keymap\": \"' + keymap + '\",\n')
keymap_json.write('\t\"layout\": \"' + layout + '\",\n')
keymap_json.write('\t\"layers\": [\n')

line = ' '
layer_no = 0
keys_string = ''
keys = ''
while (line != ''):
    line = keymap_c.readline()
    if line.find(layout) != -1:
        keys_string = ''
        keys = ''
        for count in range(layout_rows):
            keys_string += keymap_c.readline()

        # string cleaning. looking to get only keycode and comma so we can split
        keys_string = keys_string.strip()
        if keys_string[-1] == ',':
            keys_string = keys_string[:-2]
        else: keys_string = keys_string[:-1]
        keys_string = keys_string.replace(' ', '')
        keys_string = keys_string.replace('\\', '')
        keys_string = keys_string.replace('\n', '')
        keys_string = keys_string.replace('\t', '')
        keys_string = keys_string.replace('_______', 'KC_TRNS')

        keys = keys_string.split(',')

        # uses printing trick where you print the first case with no comma
        # and the others with the comma at the start
        # thx stackoverflow
        if layer_no != 0: keymap_json.write(',\n')
        keymap_json.write('\t\t[\n')
        for i, key in enumerate(keys):
            if i != 0:
                keymap_json.write(',\n')
            keymap_json.write('\t\t\t\"' + key + '\"')
        keymap_json.write('\n\t\t]')
        layer_no += 1

keymap_json.write('\n\t],\n')
keymap_json.write('\t\"author\": \"' + author + '\"\n}')

keymap_c.close()
keymap_json.close()
