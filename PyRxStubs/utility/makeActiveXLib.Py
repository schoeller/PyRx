import sys
from win32com.client import makepy
import PyRx

print("run command makeComWrappers")

def makeComAcadApplication24() -> None:
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\AxApp24.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\ARX2021\inc-x64\acax24ENU.tlb"
    sys.argv = ["makepy", "-v", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    
def makeComAcadApplication25() -> None:
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\AxApp25.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\ARX2025\inc-x64\acax25ENU.tlb"
    sys.argv = ["makepy", "-v", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    
def makeComAcadDBX24() -> None:
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\AcadDBX24.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\ARX2021\inc-x64\axdb24enu.tlb"
    sys.argv = ["makepy", "-v", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    
def makeComAcadDBX25() -> None:
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\AcadDBX25.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\ARX2025\inc-x64\axdb25enu.tlb"
    sys.argv = ["makepy", "-v", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    
def makeComETransmit20() -> None:
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\AxETransmit20.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\ARX2021\inc-x64\AcETransmit20.tlb"
    sys.argv = ["makepy", "-v", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    
def makeComSmcomponents24() -> None:
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\AxSmcomponents24.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\ARX2021\inc-x64\acsmcomponents24.tlb"
    sys.argv = ["makepy", "-v", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    
def makeComSmcomponents25() -> None:
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\AxSmcomponents25.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\ARX2025\inc-x64\acsmcomponents25.tlb"
    sys.argv = ["makepy", "-v", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()

def makeComBcadApplication24() -> None:
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\BxApp24.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\BRXSDKV24\inc-x64\axbricscadapp1.tlb"
    sys.argv = ["makepy", "-v", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    
def makeComBcadDB24() -> None:
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\BxDb24.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\BRXSDKV24\inc-x64\axbricscaddb1.tlb"
    sys.argv = ["makepy", "-v", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    
def makeComGcadApp24() -> None:
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\GxApp24.py"
    comTypeLibraryOrDLL = r"C:\Program Files\Gstarsoft\GstarCAD2024\gcax.tlb"
    sys.argv = ["makepy", "-v", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    
def makeComZcadApp24() -> None:
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\ZxApp24.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\ZWCAD_2024_ZRXSDK\lib-x64\zwcad21.tlb"
    sys.argv = ["makepy", "-v", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    
def makeComZcadApp25() -> None:
    outputFile = r"M:\Dev\Projects\PyRxGit\PyRxStubs\ZxApp25.py"
    comTypeLibraryOrDLL = r"M:\Dev\ArxSdk\ZWCAD_2025_ZRXSDK\arxport\inc-x64\zwcad25.tlb"
    sys.argv = ["makepy", "-v", "-o", outputFile, comTypeLibraryOrDLL]
    makepy.main ()
    
def PyRxCmd_makeComWrappers():
    #makeComSmcomponents24()
    #makeComSmcomponents25()
    print("done")

