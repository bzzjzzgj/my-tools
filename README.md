wxFormBuilder 4.2.1 https://github.com/wxFormBuilder/wxFormBuilder

```shell
xgettext --from-code=UTF-8 --keyword=_ -L C++ ./src/components/ui/ui.h -o ./src/locale/zh_CN/LC_MESSAGES/message.pot
msgmerge --update ./src/locale/zh_CN/LC_MESSAGES/message.po ./src/locale/zh_CN/LC_MESSAGES/message.pot
msgfmt ./src/locale/zh_CN/LC_MESSAGES/message.po -o ./src/locale/zh_CN/LC_MESSAGES/message.mo
```