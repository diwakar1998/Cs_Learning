alphaBig = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ']
alphaSmall = [' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
                 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
# for i in list(range(65, 91)) + list(range(97, 123)):
    # alphabets.append(chr(i))
    # print(alphabets)
def helper(shift,array):
    buildCode = {}
    for i in range(0, len(array)):
        shiftval = 0
        if (i + shift >= len(array)):
            shiftval = i + shift - len(array)
        else:
            shiftval = i + shift
        buildCode[array[i]] = array[shiftval]
    return buildCode

def build_encoder(shift):
    buildCode={}
    buildCode =helper(shift,alphaBig)
    buildCode.update(helper(shift,alphaSmall))
    return buildCode

def build_decoder(shift):
    shift = -1*shift
    buildCode={}
    buildCode =helper(shift,alphaBig)
    buildCode.update(helper(shift,alphaSmall))
    return buildCode

def apply_coder(text,coder):
    output=""
    for each in text:
        if each in alphaBig or each in alphaSmall:
            output+= coder[each]
        else:
            output+=each
    return output

def apply_shift(text,shift):
    return apply_coder(text,build_encoder(shift))
if __name__ == '__main__':
    print(build_encoder(3))
    print(apply_coder('change, this!',build_encoder(3)))
    print(apply_coder(apply_coder('change, this!',build_encoder(3)), build_decoder(3)))
    print(apply_shift('change, this!',3))
    print(apply_shift('This is a test.', 8))


