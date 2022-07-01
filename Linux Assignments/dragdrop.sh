echo "Trying to restart VBoxClient"

$vbox_process = Get-Process VBoxTray
Write-verbose $vbox_process
$procID = $vbox_process.id

if ($procID  -gt 0)
{    
    $cmdline = (Get-WMIObject Win32_Process -Filter "Handle=$procID").CommandLine
    Write-Verbose $cmdline

    Write-Verbose "Stopping VBoxTray"
    $vbox_process.Kill()
    $vbox_process.WaitForExit()
    Write-Verbose "VBoxTray stopped"

    Write-Verbose "Starting VBoxTray"
    Start-Process -FilePath $cmdline.Split(' ')[0]
    echo "VBoxTray Restarted. All Done"
} else {    
    Write-Warning 'Could not find existing vboxTray process. Launching direct?'
    Start-Process -FilePath "C:\Windows\System32\VBoxTray.exe"     
}