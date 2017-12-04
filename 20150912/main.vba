Sub txt2docx()

    Dim strPathName As String 'ディレクトリ名
    Dim strFileName As String 'ファイル名
    Dim strInpFileName As String '入力ファイル名
    Dim strOutFileName As String '出力ファイル名

     ' 現在のディレクトリ
    strPathName = ActiveDocument.Path
    
    ' 先頭のファイル名の取得
    strFileName = Dir(strPathName & "\*.txt", vbNormal)
    ' ファイルが見つからなくなるまで繰り返す
    Do While strFileName <> ""
        ' txtファイルを開く
        strInpFileName = strPathName + "\" + strFileName
        Documents.Open FileName:=strInpFileName, ConfirmConversions:=False, ReadOnly:=False, AddToRecentFiles:=False, PasswordDocument:="", PasswordTemplate:="", Revert:=False, WritePasswordDocument:="", WritePasswordTemplate:="", Format:=wdOpenFormatAuto, XMLTransform:="", Encoding:=932
        ' docx形式で保存
        strOutFileName = strPathName + "\" + strFileName + ".docx"
        ActiveDocument.SaveAs FileName:=strOutFileName, FileFormat:=wdFormatXMLDocument, LockComments:=False, Password:="", AddToRecentFiles:=True, WritePassword:="", ReadOnlyRecommended:=False, EmbedTrueTypeFonts:=False, SaveNativePictureFormat:=False, SaveFormsData:=False, SaveAsAOCELetter:=False
        ' windowを閉じる
        ActiveWindow.Close
        ' 次のファイル名を取得
        strFileName = Dir()
    Loop

End Sub